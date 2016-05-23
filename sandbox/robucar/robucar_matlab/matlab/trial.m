% Trying to check whether the robot does what it is supposed to do or not.

%%%%%%%%%%
% Setup. %
%%%%%%%%%%

% Clear workspace.
clear;

% Add to Matlab the path where the mex files are.
addpath('/home/carlos/ros_workspace/ipc-bridge/ipc_msgs/ipc_geometry_msgs/bin');

% Create a publisher that publishes a geometry_msgs/Twist message.
pid_twist = geometry_msgs_Twist('connect','publisher','example_module','twist');

% Not the best way to do this, but as long as it works...
addpath('/home/carlos/ros_workspace/ipc-bridge/ipc_msgs/ipc_nav_msgs/bin');

% Create a subscriber that reads nav_msgs/Odometry.
pid_odometry = nav_msgs_Odometry('connect','subscriber','odometry_module','odometry');

%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% First, we prepare the velocity command. %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Clear screen.
clc;

% Be polite and talk a little.
input('Start trial');
fprintf('\n');

% Set the time during which the speed is required.
required_time = 50;

% Set the required velocity.
linear_velocity = 0.2;
angular_velocity = -0.05;
mode = 0.0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Then, the command is sent and its odometry is stored. %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Create an empty geometry_msgs/Twist message structure.
odo_msg = nav_msgs_Odometry('empty');
odo_msg_array = [];

% Read and store odometry messages during a set amount of time.
% Get the final time from the initial time and the required time.
odo_msg = nav_msgs_Odometry('read',pid_odometry,50);
initial_time = 0;
final_time = 0;

if(~isempty(odo_msg))
    odo_msg_array = [odo_msg_array odo_msg];
    initial_time = odo_msg.header.stamp;
    final_time = initial_time + required_time;
else
    fprintf('Odometry is empty\n');
end

fprintf('Initial time is %d seconds \n',initial_time);
fprintf('Duration is %d seconds \n',required_time);
fprintf('Final time is %d seconds \n',final_time);

% Send velocity command, then start storing odometry.
sendVelocityCommand(linear_velocity,angular_velocity,mode,pid_twist);

while (1)
    odo_msg = nav_msgs_Odometry('read',pid_odometry,50);
    if(~isempty(odo_msg))
    	odo_msg_array = [odo_msg_array odo_msg];
        if (odo_msg.header.stamp > final_time)
            break;
        end
    else
        fprintf('Odometry is empty\n');
    end
end

% Stop the robot.
sendVelocityCommand(0,0,0,pid_twist);

% Store the simulation path for plotting later.
simulation_x = zeros(1,length(odo_msg_array));
simulation_y = zeros(1,length(odo_msg_array));
simulation_th = zeros(1,length(odo_msg_array));
for i=1:1:length(odo_msg_array)
    simulation_x(i) = odo_msg_array(i).pose.pose.position.x;
    simulation_y(i) = odo_msg_array(i).pose.pose.position.y;
    quaternion = zeros(1,4);
    quaternion(1) = odo_msg_array(i).pose.pose.orientation.x;
    quaternion(2) = odo_msg_array(i).pose.pose.orientation.y;
    quaternion(3) = odo_msg_array(i).pose.pose.orientation.z;
    quaternion(4) = odo_msg_array(i).pose.pose.orientation.w;
    euler = SpinCalc('QtoEA213',quaternion,0.0001,0); % Evil degrees
    simulation_th(i) = normalize(euler(3)*pi/180);
end

% Also store the linear and angular velocities.
simulation_linear_velocity = zeros(1,length(odo_msg_array));
simulation_angular_velocity = zeros(1,length(odo_msg_array));
for i=1:1:length(odo_msg_array)
    simulation_linear_velocity(i) = sqrt((odo_msg_array(i).twist.twist.linear.x)^2+(odo_msg_array(i).twist.twist.linear.y)^2);
    simulation_angular_velocity(i) = odo_msg_array(i).twist.twist.angular.z;
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% When it is finished, the expected path is computed. %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Initialize needed variables. Memory preallocation makes Matlab happy.
x = zeros(1,length(odo_msg_array));
y = zeros(1,length(odo_msg_array));
th = zeros(1,length(odo_msg_array));
time = zeros(1,length(odo_msg_array));

% Get initial pose.
x(1) = odo_msg_array(1).pose.pose.position.x;
y(1) = odo_msg_array(1).pose.pose.position.y;
quaternion = zeros(1,4);
quaternion(1) = odo_msg_array(1).pose.pose.orientation.x;
quaternion(2) = odo_msg_array(1).pose.pose.orientation.y;
quaternion(3) = odo_msg_array(1).pose.pose.orientation.z;
quaternion(4) = odo_msg_array(1).pose.pose.orientation.w;
euler = SpinCalc('QtoEA213',quaternion,0.0001,0); % Evil degrees
th(1) = normalize(euler(3)*pi/180);

% Get time vector.
for i=1:1:length(odo_msg_array)    
    time(i) = odo_msg_array(i).header.stamp;
end

% Calculate the expected path.

if (mode < 2.0) % CAR or FOUR_WHEELS
    for i=2:1:length(odo_msg_array)
        deltaT = time(i) - time(i-1);
        robot_moving = (simulation_linear_velocity(i) > 0.001);
        if (robot_moving)
            if (angular_velocity == 0)
                deltaX = linear_velocity*cos(th(i-1))*deltaT;
                deltaY = linear_velocity*sin(th(i-1))*deltaT;
                deltaTh = 0;
            else
                deltaX = (linear_velocity/angular_velocity)*(sin(th(i-1)+(angular_velocity*deltaT))-sin(th(i-1)));
                deltaY = -(linear_velocity/angular_velocity)*(cos(th(i-1)+(angular_velocity*deltaT))-cos(th(i-1)));
                deltaTh = angular_velocity*deltaT;
            end
        else
            deltaX = 0;
            deltaY = 0;
            deltaTh = 0;
        end    
        x(i) = x(i-1)+deltaX;
        y(i) = y(i-1)+deltaY;
        th(i) = normalize(th(i-1)+deltaTh);
    end
else % CRAB
    
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Finally, both results are compared. %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if (mode < 2.0) % CAR or FOUR_WHEELS

    % Plot both of them in the same figure.
    figure(1)
    clf
    hold on
    plot(x,y,'r')
    plot(simulation_x, simulation_y, 'b')
    axis equal
    hold off
    title('Comparison between expected (red) and simulated (blue) paths')

    % Plot expected orientation vs simulation orientation.
    figure(2)
    clf
    hold on
    plot (time,th,'r')
    plot (time,simulation_th,'b')
    hold off
    title('Expected (red) vs simulated (blue) angle')

    % Plot expected linear velocity vs simulation linear velocity.
    figure(3)
    clf
    hold on
    plot (time,linear_velocity,'r')
    plot (time,simulation_linear_velocity,'b')
    hold off
    title('Expected (red) vs simulation (blue) linear velocity')

    % Plot expected angular velocity vs simulation angular velocity.
    figure(4)
    clf
    hold on
    plot(time,angular_velocity, 'r')
    plot(time,simulation_angular_velocity,'b')
    hold off
    title('Expected (red) vs simulation (blue) angular velocity')

    % Plot expected angular velocity vs simulation angular velocity.
    % A moving average is used for the simulation velocity.
    mov_avg =  tsmovavg(simulation_angular_velocity, 's', 50);
    figure(5)
    clf
    hold on
    plot(time,angular_velocity, 'r')
    plot(time,mov_avg,'b')
    hold off
    title('Expected (red) vs simulation (blue) angular velocity (moving average)')

    % Average error is calculated.
    total_error = 0;
    for i=1:1:length(x)
        distance = sqrt((x(i)-simulation_x(i))^2 + (y(i)-simulation_y(i))^2);
        total_error = total_error + distance;
    end

    average_error = total_error / length(x);
    fprintf('Average error is %f \n',average_error);

else % CRAB
    
end
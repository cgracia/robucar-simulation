function sendVelocityCommand (linear_velocity, angular_velocity, mode, pid)
% Sends a velocity command to the robot.
% linear_velocity is the requested linear velocity in m/s.
% angular_velocity is the requested angular velocity in rad/s.
% mode is the requested mode:
%     0 CAR
%     1 FOUR WHEELS
%     2 CRAB
% pid is the identification of the cmd_vel publisher.

% Create an empty geometry_msgs/Twist message structure.
vel_msg=geometry_msgs_Twist('empty');

% Assign velocity commands.
vel_msg.linear.x = linear_velocity;
vel_msg.linear.y = mode;
vel_msg.linear.z = 0.0;
vel_msg.angular.x = 0.0;
vel_msg.angular.y = 0.0;
vel_msg.angular.z = angular_velocity;

% Send message.
geometry_msgs_Twist('send',pid,vel_msg);
fprintf('Velocity command sent:\n');
fprintf('    Linear velocity is %d m/s \n',linear_velocity);
fprintf('    Angular velocity is %d rad/s \n',angular_velocity);
if (mode == 0.0)
    fprintf('    Mode is CAR \n \n');
elseif (mode == 1.0)
    fprintf('    Mode is FOUR WHEELS \n \n');
elseif (mode == 2.0)
    fprintf('    Mode is CRAB\n \n');
else
    fprintf('    Warning: No mode selected \n \n');
end
    
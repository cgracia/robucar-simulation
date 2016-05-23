% IPC-Bridge Example Subscriber
% 1/24/2011
% Ben Cohen
clear all;
clc;

% add the ipc_bridge_matlab binaries to your path
%[a, p] = system('rospack find ipc_geometry_msgs');
%addpath(strcat(p, '/bin'));

% Not the best way to do this, but as long as it works...
addpath('/home/carlos/ros_workspace/ipc-bridge/ipc_msgs/ipc_nav_msgs/bin');
addpath('/home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/lib');

% create a publisher that publishes a geometry_msgs/Twist message
pid=nav_msgs_Odometry('connect','subscriber','odometry_module','odometry');

% create an empty geometry_msgs/Twist message structure
msg=nav_msgs_Odometry('empty');

% read a message and print to screen
while (1)
    msg = nav_msgs_Odometry('read',pid,50000);
    if(~isempty(msg))
      msg.pose.pose.position.x
    else
      fprintf('Odometry is empty\n');
    end
end

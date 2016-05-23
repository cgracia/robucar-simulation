#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

class Localization2tf
{
    ros::Subscriber subscriber_;
    tf::TransformBroadcaster tf_publisher_;

    void callback(const geometry_msgs::PoseWithCovarianceStamped& msg)
    {
        tf::Pose pose;

        tf::poseMsgToTF(msg.pose.pose, pose);

        tf::StampedTransform transform(pose, msg.header.stamp, "odom", "base_link");
        tf_publisher_.sendTransform(transform);
    }

public:
    Localization2tf()
    {
        ros::NodeHandle node;
        subscriber_ = node.subscribe("/localization/out", 10, &Localization2tf::callback, this);
    }
};

int main (int argc, char **argv)
{
    ros::init(argc, argv, "localization2tf");

    Localization2tf localization2tf;

    ros::spin();

    return 0;
}

#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <rosbucar/CarLikeInfo.h>

class CarOdom
{
public:
    CarOdom(const float l);

    void callback(const rosbucar::CarLikeInfo& message);

private:
    const float L_;
    bool is_initialized_;
    tf::Transform current_odom_;
    ros::Time previous_stamp_;


    //ros
    ros::Subscriber subscriber_;
    ros::Publisher publisher_;
    //tf::TransformBroadcaster tf_broadcaster_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "car2odom");


    CarOdom car_odom(1.2);

    ros::spin();
}

CarOdom::CarOdom(const float l):
    L_(l), is_initialized_(false)
{
    current_odom_.setIdentity();
    ros::NodeHandle node;

    subscriber_ = node.subscribe<const rosbucar::CarLikeInfo&>("car/out", 50, &CarOdom::callback, this);
    publisher_ = node.advertise<nav_msgs::Odometry>("car_odom", 50);
}


void CarOdom::callback(const rosbucar::CarLikeInfo& message)
{
    if (is_initialized_)
    {
        float phi = message.current_steering;
        float v = message.current_speed;
        float w = v * tan(phi)/L_;
        float theta = tf::getYaw(current_odom_.getRotation());
        float t = (message.header.stamp - previous_stamp_).toSec();

        if (std::abs(v) > 1e-6) //stopped
        {
            if (std::abs(phi) < 1e-6) //no rotation
            {
                current_odom_.getOrigin() += v * t * tf::Vector3(cos(theta), sin(theta), 0);
            }
            else //rotation
            {
                float angle = w * t + theta;
                current_odom_.setRotation(tf::createQuaternionFromYaw(angle));
                current_odom_.getOrigin() += L_/tan(phi) * tf::Vector3(sin(angle) - sin(theta), cos(theta) - cos(angle), 0);
            }
        }

        nav_msgs::Odometry odom_msg;

        odom_msg.header.stamp = message.header.stamp;
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_link";
        tf::poseTFToMsg(current_odom_, odom_msg.pose.pose);
        odom_msg.twist.twist.linear.x = v;
        odom_msg.twist.twist.linear.y = 0;
        odom_msg.twist.twist.angular.z = w;

        publisher_.publish(odom_msg);
    }

    is_initialized_ = true;
    previous_stamp_ = message.header.stamp;
}

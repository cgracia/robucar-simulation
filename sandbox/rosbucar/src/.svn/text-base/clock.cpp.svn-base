#include <ros/ros.h>
#include <rosgraph_msgs/Clock.h>
#include <rosbucar/CarLikeInfo.h>

class Clock
{
public:
    Clock(const std::string& topic);

private:
    ros::Subscriber subscriber_;
    ros::Publisher publisher_;

    void callback(rosbucar::CarLikeInfoConstPtr msg);
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "evaclock");

    Clock clock("/car/out");

    ros::spin();

    return 0;
}

Clock::Clock(const std::string& topic)
{
    ros::NodeHandle node;
    subscriber_ = node.subscribe<rosbucar::CarLikeInfoConstPtr>(topic, 50, &Clock::callback, this);
    publisher_ = node.advertise<rosgraph_msgs::Clock>("/clock", 50);
}

inline void Clock::callback(rosbucar::CarLikeInfoConstPtr msg)
{
    rosgraph_msgs::Clock output;

    output.clock = msg->header.stamp;

    publisher_.publish(output);
}

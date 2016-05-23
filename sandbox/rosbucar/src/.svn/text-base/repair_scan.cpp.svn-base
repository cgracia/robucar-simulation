#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class RepairScan
{
public:
    RepairScan(float min_angle, float max_angle):
        min_angle_(min_angle), max_angle_(max_angle)
    {
        ros::NodeHandle node;
        subscriber_ = node.subscribe("in", 25, &RepairScan::callback, this);
        publisher_ = node.advertise<sensor_msgs::LaserScan>("out", 25);
    }

private:
    float min_angle_, max_angle_;

    ros::Subscriber subscriber_;
    ros::Publisher publisher_;

    void callback(sensor_msgs::LaserScanConstPtr input)
    {
        sensor_msgs::LaserScan output = *input;

        output.angle_min = min_angle_;
        output.angle_max = max_angle_;

        publisher_.publish(output);

    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "repair_scan");

    RepairScan repair_scan(-M_PI/2, M_PI/2);

    ros::spin();

    return 0;
}

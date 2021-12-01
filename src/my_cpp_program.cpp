#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void chatterCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
    int size = scan->range.size();
    int middle = size/2;
    float range = scan->range[middle];
  
    ROS_INFO("Range[%d] = %f", middle, range);
  
}

int main(int argc, char *argv)
{
    ros::init(argc, argv, "my_node");
    ros::NodeHandle nh;
  
    ros::Subscriber sub = nh.subscribe("/sick_s300_front/scan". 1, chatterCallback);
  
    ros::spin();
  
    return 0;
}

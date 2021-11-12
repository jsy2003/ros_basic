#include <ros/ros.h>

int main(int argc, char **argv)
{
    int count =0;
    ros::init(argc, argv, "simple_node");   // Node declared with name => simple_node
    ros::NodeHandle nh;                     // NodeHandle will initialize the node
    ros::Rate loop_rate(10);                // 10 hz
  
    while(ros::ok())                        // run the until ctrl-C
    {
        ROS_INFO("simple_node in cpp is runnig. count=%d", count);
        
        ros::spinOnce();  // sinOnce() is used to call the callback
        count++;
        loop_rate.sleep();  // this makes the loop 10hz => 10ms 
    }
}

#include <ros/ros.h>
#include <std_msgs/Int32.h>

void subCallback(const std_msgs::Int32::Constptr &msg)
{
    ROS_INFO("received data from topic_cpp : [%ld]", msg->data);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "subsciber_cpp_node");
    ros::NodeHandle nh;
  
    /*
      A subscriber is registered in the below line.
      1. argument is the name of the topic to be subscribed. 
      2. argument is the queue_size which is used to buffer up the messages. 
      3. argument is the name of the callback method. Whenever data is published on topic "topic_cpp", my_callback is called.
    */
    ros::Subscriber sub = nh.subscribe("topic_cpp", 10, subCallback);
    ROS_INFO("ubscriber_cpp node started and subscribed to topic_cpp");
  
    ros::spin();
  
    return 0;
}

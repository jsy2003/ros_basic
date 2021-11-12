#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_cpp");
    ros::NodeHandle nh;
    
    /*
        A Publisher is created in the below line
        First argument is the name of the topic.
        Second argument is queue_size which is used to buffer up a maximum of 10 messages 
            before beginning to throw away old ones if we are publishing too quickly
        This publisher is using Int32 message to publish data on "topic_cpp" 
    */
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic_cpp", 10);
    ROS_INFO("publisher_cpp node started and publishing data on topic_cpp");
    ros::Rate loop_rate(10);
    
    // http://docs.ros.org/en/jade/api/std_msgs/html/msg/Int32.html
    std_msgs::Int32 count;  
    count.data = 0;
    
    while(ros::ok())
    {
        pub.publish(count);
        count.data++;
        loop_rate.sleep();
    }
    
    return 0;
}

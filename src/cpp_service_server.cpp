#include <ros/ros.h>

//http://docs.ros.org/en/jade/api/rospy_tutorials/html/srv/AddTwoInts.html
#include <rospy_tutorials/AddTwoInts.h>



bool myServer(rospy_tutorials::AddTwoInts::Request &req, rospy_tutorials::AddTwoInts::Response &res)
{
    ROS_INFO("Request received to add : x= %ld and y=%ld", (long int)req.a, (long int)req.b);
    res.sum = req.a + req.b;
    return true;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_server_cpp_node");
    ros::NodeHandle nh;

    /*
        A service server is created in the below line.
        First argument is the name of the Service. Service with name "add_cpp" is registered. 
        Second argument is the name of the callback method. This callback method is called whenever the client request for service.
    */
   ros::ServiceServer service = nh.advertiseService("add_cpp", myServer);
   ROS_INFO("Cpp Service server ready to add two numbers");
   ros::spin();

   return 0;


}

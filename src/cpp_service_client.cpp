#include <ros/ros.h>

//http://docs.ros.org/en/jade/api/rospy_tutorials/html/srv/AddTwoInts.html
#include <rospy_tutorials/AddTwoInts.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client_node_cpp");
    ros::NodeHandle nh;

    /*
        A service client is created in the below line. 
        Argument is the name of the service to be regitered.
        This service-client is using "AddTwoInts" message type to communicate. 
    */
    ros::ServiceClient client = nh.serviceClient<rospy_tutorials::AddTwoInts>("add_cpp");
    rospy_tutorials::AddTwoInts var; 
    ros::Rate loop_rate(1);

    var.request.a = 0;
    var.request.b = 1;

    int element = 1;

    ROS_INFO("Fibanocci series element %ld = %ld", (long int)element, var.response.sum);
    while(ros::ok())
    {
        client.call(var);
        ROS_INFO("Fibanocci series element %ld = %ld", (long int)element, var.response.sum);
        var.request.a = var.request.b;
        var.request.b = var.response.sum;
		element++;

        loop_rate.sleep();
    }

    return 0;

}

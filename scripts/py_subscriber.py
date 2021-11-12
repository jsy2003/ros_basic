#!/usr/bin/env python3
import rospy

from std_msgs.msg import Int32

def subCallback(msg):
    rospy.loginfo("received data from topic_py : %d", msg.data)


rospy.init_node("py_subscriber_node")
rospy.Subscriber("topic_py", Int32, subCallback, queue_size=10)
rospy.loginfo("subscriber_py node started and subscribed to topic_py") #debug statement
rospy.spin()

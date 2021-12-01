#!usr/bin/env python

import rospy
from geometry_msgs,msg import Twist
import time

class myRobot():
  def __init__(self, name, speed):
      self.robot_name = name
      self.max_speed = speed
      self.current_speed = 0.0
      self.wheels_pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
      time.sleep()
      print("Robot init")
  def set_speed(self, speed):
      print("Sendind speed: " + str(speed))
      self.current_speed = speed
      speed_cmd = Twist()
      speed_cmd.linear.x = speed
      self.wheels_pub.publish(speed_cmd)
      
rospy.init_node("my_node")
robot = myRobot("pepito", 0.5)
rosot.set_speed(0.2)
rospy.spin()


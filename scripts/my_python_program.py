#!usr/bin/env python

import rospy
from sensor_msgs import LaserScan

def process_scan(scan):
  print len(scan)
  middle_ray = scan[360]
  print(middle_ray)
  
def get_scan(msg):
  process_scan(msg.ranges)

rospy.init_node("my_node")
laser_subs = rospy.Subscriber("/scan", LaserScan, get_scan)
rospy.spin()

# chmod +x my_python_program.py

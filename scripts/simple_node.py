imporrt rospy

count=0
rospy.init_node("simple_node_py")
rate = rospy.Rate(10)

while not rospy.is_suhtdown():
  rospy.loginfo("simple_node in python is running. count= %d",count) #debug statement
  count +=1
  tate.sleep()
  

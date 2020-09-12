import rospy    # Main header for ROS
from std_msgs.msg import String    # From the std_msgs class import the String

def talker(): # After the main function is executed this talker function will be activated
    pub = rospy.Publisher('chatter', String, queue_size=10) # Pusblishes the chatter topic of type String
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # Defines the rate of communication 
    while not rospy.is_shutdown():  # Check to see if CTRL+C is pressed
        hello_str = "My first ROS code in Python %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':    # This is the main function that will be executed first
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

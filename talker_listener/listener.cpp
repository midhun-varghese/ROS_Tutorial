#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 This is the callback function that will get called when a new message has arrived on the chatter topic.
*/
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("My first ROS node was a success and I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  /*
   This is the main function for the ROS package/code and it needs two arguments as given above.
   This initializes ROS and here we specify the name of the node.
  */
  ros::init(argc, argv, "listener");

  /**
   This section creates a nodehandle for the node
   NodeHandle is the main access point to communications with the ROS system.
  */
  ros::NodeHandle n;

  /**
   Subscribe to the chatter topic with the master. ROS will call the chatterCallback() function 
   whenever a new message arrives. The 2nd argument is the queue size
  */
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}Subscribe to the chatter topic with the master. ROS will call the chatterCallback() function whenever a new message arrives. The 2nd argument is the queue size
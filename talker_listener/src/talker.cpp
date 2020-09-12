#include "ros/ros.h"  /* To include the ROS header file*/
#include "std_msgs/String.h"  /* Header file for to include the std_msgs from the package*/ 
#include <sstream> 


int main(int argc, char **argv)
{
  /*
   This is the main function for the ROS package/code and it needs two arguments as given above.
   This initializes ROS and here we specify the name of the node.
   */
  ros::init(argc, argv, "talker");

  /**
   This section creates a nodehandle for the node
   NodeHandle is the main access point to communications with the ROS system.
  */
  ros::NodeHandle n;

  /**
   Tell the master that we are going to be publishing a message of type std_msgs/String on the topic chatter
   The advertis function receives two arguments, first the message and the second the size of the message
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  /**
   Allows to specify the frequency at which to loop
   */
  ros::Rate loop_rate(0.5);

  /**
   Allows to specify the frequency at which to loop
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     By default roscpp will install a SIGINT handler which provides Ctrl-C 
     handling which will cause ros::ok() to return false if that happens. 
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "This is my first ROS Node " << count;
    msg.data = ss.str();
       
    ROS_INFO("%s", msg.data.c_str());

    /*
     Broadcast the message to anyone who is connected 
    */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
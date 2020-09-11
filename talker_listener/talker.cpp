#include "ros/ros.h"  /* To include the ROS header file*/
#include "std_msgs/String.h"  /* Header file for standard*/ 
#include <sstream> 


int main(int argc, char **argv)
{
  /*
   This is the main function for the ROS package/code and it needs two arguments as given above
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
  */
  ros::NodeHandle n;

  /**
   The advertis function receives two arguments, first the message and the second the size of the message
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "This is my first ROS node" << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
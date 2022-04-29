#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
int main (int argc ,char** argv ){
  ros::init( argc ,  argv ,"ros_publisher") ;
  ros::NodeHandle nh ;
  ros::Publisher topic_pub = nh.advertise< std_msgs::Int32 >("/number",10) ;
  ros::Rate rate (10) ;
  int count = 0;
  std_msgs::Int32 msg ;

  while( ros::ok () ){
    msg.data = count++;
    std::cout <<"Data" << msg.data << std::endl;
    topic_pub.publish (msg) ;
    rate.sleep();
  }
  return 0;
}

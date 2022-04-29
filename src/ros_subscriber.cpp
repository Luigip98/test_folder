#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "boost/thread.hpp"


class ROS_SUB{
  public:
    ROS_SUB();
    void topic_sub ( std_msgs::Int32ConstPtr );
    void reader();
    void run();
  private:
    ros::NodeHandle _nh;
    ros::Subscriber _topic_sub;
    int _data;

};


ROS_SUB::ROS_SUB(){

  _topic_sub = _nh.subscribe( "/number", 1, &ROS_SUB::topic_sub, this);

}

void ROS_SUB::topic_sub ( std_msgs::Int32ConstPtr d){
  std::cout << "Sub value" << d->data<<std::endl;
  _data = d->data;

}

void ROS_SUB::reader(){

 ros::Rate r(10);
 while(ros::ok()){
 
 std::cout<< "_data" << _data<<std::endl;
 r.sleep();
 }

}

void ROS_SUB::run(){
 
 boost::thread reader_t ( &ROS_SUB::reader, this);	
 ros::spin();
 
 
}




int main (int argc ,char** argv ){

  ros::init( argc, argv,"subs") ;
  ROS_SUB rs;
  rs.run();
  ros::spin();
  return 0;
}

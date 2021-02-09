#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("The result is: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc,argv,"listener");
  ros::NodeHandle nh;
  ROS_INFO("Awaiting results.....");
  ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
  ros::spin();

  return 0;
}

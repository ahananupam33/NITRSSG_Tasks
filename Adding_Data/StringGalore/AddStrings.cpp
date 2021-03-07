#include "ros/ros.h"
#include "beginner_tutorials_ros/FullWord.h"

bool addstr(beginner_tutorials_ros::FullWord::Request &req,
	    beginner_tutorials_ros::FullWord::Response &res)
{
  res.word = req.f + req.l;
  ROS_INFO("request: f=%s, l=%s", req.f, req.l);
  ROS_INFO("sending response: [%s]", res.word);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_strings_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_strings", addstr);
  ros::spin();
  return 0;
}

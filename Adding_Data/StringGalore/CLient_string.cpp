#include "ros/ros.h"
#include "beginner_tutorials_ros/FullWord.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_strings_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_strings_client f l");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials_ros::FullWord>("add_strings");
  beginner_tutorials_ros::FullWord srv;
  srv.request.f = atoll(argv[1]);
  srv.request.l = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Word: %s", srv.response.word);
  }
  else
  {
    ROS_ERROR("Failed to call service add_strings");
    return 1;
  }

  return 0;
}

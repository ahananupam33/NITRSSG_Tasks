#include "ros/ros.h"
#include "beginner_tutorials_ros/Multiply2.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Multiply_client");
  if (argc != 3)
  {
    ROS_INFO("usage: Multiplying a b");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials_ros::Multiply2>("Multiplier");
  beginner_tutorials_ros::Multiply2 srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Product: %ld", (long int)srv.response.ans);
  }
  else
  {
    ROS_ERROR("Failed to call service name_maker");
    return 1;
  }

  return 0;
}

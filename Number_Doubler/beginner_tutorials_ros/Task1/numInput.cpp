#include "ros/ros.h"
#include "beginner_tutorials_ros/Multiply2.h"
#include <cstdlib>
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "num_input");
    if (argc != 2)
    {
      ROS_INFO("usage: num_input n");
      return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<beginner_tutorials_ros::Multiply2>("double_the_number");
    beginner_tutorials_ros::Multiply2 srv;
    srv.request.n = atoll(argv[1]);
    if (client.call(srv))
    {
      int loop = 0;
      ros::Rate loop_rate(1);
      ros::Publisher num_publisher = nh.advertise<std_msgs::String>("chatter", 1000);
      while(loop<2)
      {
        std_msgs::String msg;
        std::stringstream ss;
        ss << (long int)srv.response.ans;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        num_publisher.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++loop;
       }
    }
    else
    {
      ROS_ERROR("Failed to call service double_the_number");
      return 1;
    }
    return 0;
}

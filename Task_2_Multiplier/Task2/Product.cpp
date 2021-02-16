#include "ros/ros.h"
#include "beginner_tutorials_ros/Multiply2.h"

bool Multiply(beginner_tutorials_ros::Multiply2::Request &in, beginner_tutorials_ros::Multiply2::Response &out)
{
	out.ans = in.a * in.b;
	ROS_INFO("Request: first num: %ld, last num: %ld", (long int)in.a, (long int)in.b);
	ROS_INFO("Sending back product: %ld", (long int)out.ans);
	return true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Multiply_server");
	ros::NodeHandle nh;
	ros::ServiceServer service = nh.advertiseService("Multiplier", Multiply);
	ROS_INFO("Ready to find product");
	ros::spin();
	return 0;
}

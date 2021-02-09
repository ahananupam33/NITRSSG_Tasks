#include "ros/ros.h"
#include "beginner_tutorials_ros/Multiply2.h"
#include "std_msgs/String.h"
#include "bits/stdc++.h"
#include <sstream>

bool numdouble(beginner_tutorials_ros::Multiply2::Request &req, beginner_tutorials_ros::Multiply2::Response &res)
{
    res.ans = req.n * 2;
    ROS_INFO("request: n=%ld", (long int)req.n);
    ROS_INFO("sending back response: [%ld]", (long int)res.ans);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "doubler");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("double_the_number", numdouble);

    ROS_INFO("Ready to double.");
    ros::spin();
    return 0;
}

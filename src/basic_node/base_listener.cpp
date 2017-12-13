#include <ros/ros.h>
#include <sensor_msgs/Imu.h>


void callBack (const sensor_msgs::Imu &msg)
{
    ROS_INFO("msg.linear_acceleration.x = %f", msg.linear_acceleration.x);
}

int main (int argc, char** argv)
{
    ros::init(argc, argv, "your_listener_node_name");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("base_topic2", 1000 , &callBack);
    ros::Rate rate (10); // 10hz


    while (ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}


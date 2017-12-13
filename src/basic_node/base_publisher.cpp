#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "what_is_your_node_name");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<sensor_msgs::Imu>("base_topic1", 1000);
    ros::Rate rate(10); //10hz

    while (ros::ok())
    {
        sensor_msgs::Imu msg;
        
        //input your Imu msgs;
        msg.linear_acceleration.x = 100;
        
        pub.publish(msg);
        rate.sleep();
    }


    return 0;
}



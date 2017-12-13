#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

int data;


void callBack (const sensor_msgs::Imu &msg)
{
   data = msg.linear_acceleration.x;
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "your_node_name");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("base_topic1", 1000 , callBack);
  ros::Publisher  pub = n.advertise<sensor_msgs::Imu>("base_topic2", 1000);
  ros::Rate rate (10); // 10Hz

  while (ros::ok())
  {
    sensor_msgs::Imu msg;
    
    //recieve data from previse topic
    ros::spinOnce();
  
    //do some calculate about the date received.
    data += 1; 
  
    //input the result to publisher msg.
    msg.linear_acceleration.x = data;
    
    //post-process
    pub.publish(msg);
    data = 0;
    rate.sleep();
  }


  




  return 0;
}





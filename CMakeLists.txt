cmake_minimum_required(VERSION 2.8.3)
project(teleop_tx1)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rosconsole
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
  message_generation
)
## Generate services in the 'srv' folder
 add_service_files(
   FILES
   AddTwoInts.srv
)
## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   geometry_msgs   sensor_msgs   std_msgs actionlib_msgs
 )
catkin_package(
  CATKIN_DEPENDS geometry_msgs rosconsole roscpp rospy sensor_msgs std_msgs tf actionlib_msgs
)

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS})

add_executable(base_listener  src/basic_node/base_listener.cpp)
add_executable(base_publisher src/basic_node/base_publisher.cpp)
add_executable(base_server src/basic_node/add_two_ints_server.cpp)
add_executable(base_client src/basic_node/add_two_ints_client.cpp)
add_executable(base_listenAndTalk src/basic_node/base_listenAndTalk.cpp)

 target_link_libraries(base_publisher
   ${catkin_LIBRARIES}
 )
 target_link_libraries(base_listener
   ${catkin_LIBRARIES}
 )
 target_link_libraries(base_server
   ${catkin_LIBRARIES}
 )
 target_link_libraries(base_client
   ${catkin_LIBRARIES}
 )
 target_link_libraries(base_listenAndTalk
   ${catkin_LIBRARIES}
 )

#############
## Install ##
#############

catkin_install_python(PROGRAMS
    script/display_3D_visualization.py
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/nodes
)


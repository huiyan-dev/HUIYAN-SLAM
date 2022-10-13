cmake_minimum_required(VERSION 3.2)

project(huiyan_slam)

find_package(
    catkin REQUIRED COMPONENTS
    roscpp
    rospy
    sensor_msgs
    image_transport
    cv_bridge
    nav_msgs
    tf2_ros
)

find_package(Eigen3 3.4.0 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Open3D REQUIRED)
find_package(glog REQUIRED)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp rospy
    DEPENDS
)
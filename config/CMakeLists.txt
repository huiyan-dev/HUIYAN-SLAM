cmake_minimum_required(VERSION 3.2)

project(huiyan_slam)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -pthread")

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

add_message_files(
    DIRECTORY msgs
    FILES
    cloud_info.msg
)

generate_messages(
    DEPENDENCIES
    geometry_msgs
    std_msgs
    nav_msgs
    sensor_msgs
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp rospy
    DEPENDS
)

include_directories(include)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(feature_loam modules/frontend/features/feature_loam.cc)
target_link_libraries(
    feature_loam
    ${catkin_LIBRARIES}
    ${OpenCV_LIBS}
    glog::glog
    Eigen3::Eigen
)
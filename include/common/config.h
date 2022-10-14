//
// Created by huiyan on 10/14/22.
//

#pragma once
// for log
#include <glog/logging.h>
// ros
#include <ros/ros.h>
// std
#include <string>

namespace huiyan {
namespace common {

class Config {
public:
    static std::shared_ptr<Config> GetInstance();
    Config(Config *config) = delete;
    Config &operator=(const Config &config) = delete;
    ~Config() = default;

    ros::NodeHandle nh;

    std::string topic_name_imu{"kitti360/data_imu_raw/data_imu_raw"};
    std::string topic_name_left_perspective{"kitti360/data_2d_raw/left_perspective"};
    std::string topic_name_right_perspective{"kitti360/data_2d_raw/right_perspective"};
    std::string topic_name_lidar_velo{"kitti360/data_3d_raw/lidar_velo"};
    std::string topic_name_gt_path{"kitti360/data_poses/gt_path"};
    std::string topic_name_gt_odom{"kitti360/data_poses/gt_odom"};

    std::string frame_id_world{"world"};
    std::string frame_id_lidar{"lidar"};
    std::string frame_id_cam0{"cam0"};
    std::string frame_id_cam1{"cam1"};
    std::string frame_id_imu{"imu"};

    std::string data_output_dir{"output/"};

    Config() {
        nh.getParam("kitti360/topic_name_imu", topic_name_imu);
        nh.getParam("kitti360/topic_name_left_perspective", topic_name_left_perspective);
        nh.getParam("kitti360/topic_name_right_perspective", topic_name_right_perspective);
        nh.getParam("kitti360/topic_name_lidar_velo", topic_name_lidar_velo);
        nh.getParam("kitti360/topic_name_gt_path", topic_name_gt_path);
        nh.getParam("kitti360/topic_name_gt_odom", topic_name_gt_odom);

        nh.getParam("huiyan_slam/frame_id_world", frame_id_world);
        nh.getParam("huiyan_slam/frame_id_lidar", frame_id_lidar);
        nh.getParam("huiyan_slam/frame_id_cam0", frame_id_cam0);
        nh.getParam("huiyan_slam/frame_id_cam1", frame_id_cam1);
        nh.getParam("huiyan_slam/frame_id_imu", frame_id_imu);

        nh.getParam("huiyan_slam/data_output_dir", data_output_dir);
    }

private:
    static std::shared_ptr<Config> instance_;
    static std::mutex instance_mtx_;
};

std::shared_ptr<Config> Config::instance_{nullptr};
std::shared_ptr<Config> Config::GetInstance() {
    if (instance_) {
        return instance_;
    }
    instance_mtx_.lock();
    if (!instance_) {
        instance_ = std::make_shared<Config>(Config());
        instance_mtx_.unlock();
        return instance_;
    }
    instance_mtx_.unlock();
    return instance_;
}
std::mutex Config::instance_mtx_;

}
}// namespace huiyan::common

/*
 * SPDX-FileCopyrightText: 2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_ROS2_LOCALIZATION2D_NWS_ROS2_H
#define YARP_ROS2_LOCALIZATION2D_NWS_ROS2_H

#include <yarp/dev/WrapperSingle.h>
#include <yarp/dev/ILocalization2D.h>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/os/PeriodicThread.h>
#include <yarp/os/Stamp.h>
#include "Localization2D_nws_ros2_ParamsParser.h"

#include <rclcpp/rclcpp.hpp>
#include <tf2_msgs/msg/tf_message.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <yarp/math/Math.h>

#include <mutex>

/**
 *  @ingroup dev_impl_nws_ros2 dev_impl_navigation
 *
 * \brief `Localization2D_nws_ros2`:  A localization server which can be wrap multiple algorithms and devices to provide robot localization in a 2D World.
 *
 * Parameters required by this device are shown in class: Localization2D_nws_ros2_ParamsParser
 *
 *  Documentation to be added
 *
 */
class Localization2D_nws_ros2 :
        public yarp::dev::DeviceDriver,
        public yarp::os::PeriodicThread,
        public yarp::dev::WrapperSingle,
        Localization2D_nws_ros2_ParamsParser
{
public:
    Localization2D_nws_ros2();
    Localization2D_nws_ros2(const Localization2D_nws_ros2&) = delete;
    Localization2D_nws_ros2(Localization2D_nws_ros2&&) noexcept = delete;
    Localization2D_nws_ros2& operator=(const Localization2D_nws_ros2&) = delete;
    Localization2D_nws_ros2& operator=(Localization2D_nws_ros2&&) noexcept = delete;
    ~Localization2D_nws_ros2() override = default;

    bool attach(yarp::dev::PolyDriver* poly) override;
    bool detach() override;

    // DeviceDriver
    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    // PeriodicThread
    void run() override;

private:
    void publish_odometry_on_ROS_topic();
    void publish_odometry_on_TF_topic();

private:
    yarp::dev::PolyDriver m_driver;
    yarp::dev::Nav2D::ILocalization2D *m_iLoc = nullptr;
    rclcpp::Node::SharedPtr m_node;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr   m_publisher_odom;
    rclcpp::Publisher<tf2_msgs::msg::TFMessage>::SharedPtr  m_publisher_tf;
    bool m_isDeviceOwned = false;

    std::string m_robot_frame;
    std::string m_fixed_frame;


    double                                  m_stats_time_last;
    yarp::os::Stamp                         m_loc_stamp;
    yarp::os::Stamp                         m_odom_stamp;

    yarp::dev::OdometryData                     m_current_odometry;
    yarp::dev::Nav2D::Map2DLocation             m_current_position;
    yarp::dev::Nav2D::LocalizationStatusEnum    m_current_status;
};

#endif // YARP_ROS2_LOCALIZATION2D_NWS_ROS2_H

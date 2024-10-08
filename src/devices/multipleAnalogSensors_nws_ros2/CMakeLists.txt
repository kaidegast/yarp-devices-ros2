# SPDX-FileCopyrightText: 2023 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

yarp_prepare_plugin(wrenchStamped_nws_ros2
  CATEGORY device
  TYPE WrenchStamped_nws_ros2
  INCLUDE WrenchStamped_nws_ros2.h
  EXTRA_CONFIG
    WRAPPER=wrenchStamped_nws_ros2
  DEPENDS "TARGET YARP::YARP_math"
  DEFAULT ON
)

if(ENABLE_wrenchStamped_nws_ros2)
  yarp_add_plugin(yarp_wrenchStamped_nws_ros2)
  generateDeviceParamsParser(GenericSensor_nws_ros2 genericSensor_nws_ros2)

  target_sources(yarp_wrenchStamped_nws_ros2
    PRIVATE
      WrenchStamped_nws_ros2.cpp
      WrenchStamped_nws_ros2.h
      GenericSensor_nws_ros2.h
      GenericSensor_nws_ros2_ParamsParser.h
      GenericSensor_nws_ros2_ParamsParser.cpp
  )

  target_link_libraries(yarp_wrenchStamped_nws_ros2
    PRIVATE
      YARP::YARP_os
      YARP::YARP_sig
      YARP::YARP_dev
      rclcpp::rclcpp
      geometry_msgs::geometry_msgs__rosidl_typesupport_cpp
      Ros2Utils
  )

  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
    YARP_os
    YARP_sig
    YARP_dev
  )

  yarp_install(
    TARGETS yarp_wrenchStamped_nws_ros2
    EXPORT YARP_${YARP_PLUGIN_MASTER}
    COMPONENT ${YARP_PLUGIN_MASTER}
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
    YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
  )

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_wrenchStamped_nws_ros2 PROPERTY FOLDER "Plugins/Device")
endif()

yarp_prepare_plugin(imu_nws_ros2
  CATEGORY device
  TYPE Imu_nws_ros2
  INCLUDE Imu_nws_ros2.h
  EXTRA_CONFIG
    WRAPPER=imu_nws_ros2
  DEPENDS "TARGET YARP::YARP_math"
  DEFAULT ON
)

if(ENABLE_imu_nws_ros2)
  yarp_add_plugin(yarp_imu_nws_ros2)

  target_sources(yarp_imu_nws_ros2
    PRIVATE
      Imu_nws_ros2.cpp
      Imu_nws_ros2.h
      GenericSensor_nws_ros2.h
      GenericSensor_nws_ros2_ParamsParser.h
      GenericSensor_nws_ros2_ParamsParser.cpp
  )

  target_link_libraries(yarp_imu_nws_ros2
    PRIVATE
      YARP::YARP_os
      YARP::YARP_sig
      YARP::YARP_dev
      rclcpp::rclcpp
      sensor_msgs::sensor_msgs__rosidl_typesupport_cpp
      tf2::tf2
      Ros2Utils
  )

  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
    YARP_os
    YARP_sig
    YARP_dev
  )

  yarp_install(
    TARGETS yarp_imu_nws_ros2
    EXPORT YARP_${YARP_PLUGIN_MASTER}
    COMPONENT ${YARP_PLUGIN_MASTER}
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
    YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
  )

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_imu_nws_ros2 PROPERTY FOLDER "Plugins/Device")

  if(YARP_COMPILE_TESTS)
    add_subdirectory(tests)
  endif()

endif()

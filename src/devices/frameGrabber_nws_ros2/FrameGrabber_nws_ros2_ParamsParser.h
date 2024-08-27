/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Fri Aug  2 11:04:53 2024


#ifndef FRAMEGRABBER_NWS_ROS2_PARAMSPARSER_H
#define FRAMEGRABBER_NWS_ROS2_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FrameGrabber_nws_ros2.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description                                   | Notes                             |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:---------------------------------------------:|:---------------------------------:|
* | -          | period         | double | s     | 0.02          | 0        | refresh period of the broadcasted values in s | optional, default 20ms            |
* | -          | node_name      | string | -     | -             | 1        | set the name for ROS node                     | must not start with a leading '/' |
* | -          | topic_name     | string | -     | -             | 1        | set the name for ROS topic                    | must start with a leading '/'     |
* | -          | frame_id       | string | -     | -             | 1        | set the name for the reference frame          | must not start with a leading '/' |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device frameGrabber_nws_ros2 --period 0.02 --node_name <mandatory_value> --topic_name <mandatory_value> --frame_id <mandatory_value>
* \endcode
*
* \code{.unparsed}
* yarpdev --device frameGrabber_nws_ros2 --node_name <mandatory_value> --topic_name <mandatory_value> --frame_id <mandatory_value>
* \endcode
*
*/

class FrameGrabber_nws_ros2_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FrameGrabber_nws_ros2_ParamsParser();
    ~FrameGrabber_nws_ros2_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FrameGrabber_nws_ros2"};
    const std::string m_device_name = {"frameGrabber_nws_ros2"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_period_defaultValue = {"0.02"};
    const std::string m_node_name_defaultValue = {""};
    const std::string m_topic_name_defaultValue = {""};
    const std::string m_frame_id_defaultValue = {""};

    double m_period = {0.02};
    std::string m_node_name = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_topic_name = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_frame_id = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
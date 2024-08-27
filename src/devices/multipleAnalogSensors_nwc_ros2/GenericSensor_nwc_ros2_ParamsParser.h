/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Aug  5 16:25:52 2024


#ifndef GENERICSENSOR_NWC_ROS2_PARAMSPARSER_H
#define GENERICSENSOR_NWC_ROS2_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class GenericSensor_nwc_ros2.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description                                              | Notes                              |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:--------------------------------------------------------:|:----------------------------------:|
* | -          | node_name      | string | -     | -             | 1        | name of the ros2 node                                    | must not start with an initial '/' |
* | -          | topic_name     | string | -     | -             | 1        | name of the topic where the device must publish the data | must begin with an initial '/'     |
* | -          | sensor_name    | string | -     | -             | 1        | The name of the sensor the data are coming from          | -                                  |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device genericSensor_nwc_ros2 --node_name <mandatory_value> --topic_name <mandatory_value> --sensor_name <mandatory_value>
* \endcode
*
* \code{.unparsed}
* yarpdev --device genericSensor_nwc_ros2 --node_name <mandatory_value> --topic_name <mandatory_value> --sensor_name <mandatory_value>
* \endcode
*
*/

class GenericSensor_nwc_ros2_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    GenericSensor_nwc_ros2_ParamsParser();
    ~GenericSensor_nwc_ros2_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"GenericSensor_nwc_ros2"};
    const std::string m_device_name = {"genericSensor_nwc_ros2"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_node_name_defaultValue = {""};
    const std::string m_topic_name_defaultValue = {""};
    const std::string m_sensor_name_defaultValue = {""};

    std::string m_node_name = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_topic_name = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_sensor_name = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
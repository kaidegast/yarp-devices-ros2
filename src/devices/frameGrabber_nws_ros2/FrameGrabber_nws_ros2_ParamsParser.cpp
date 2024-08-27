/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Fri Aug  2 11:04:53 2024


#include "FrameGrabber_nws_ros2_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FrameGrabber_nws_ros2ParamsCOMPONENT, "yarp.device.FrameGrabber_nws_ros2")
}


FrameGrabber_nws_ros2_ParamsParser::FrameGrabber_nws_ros2_ParamsParser()
{
}


std::vector<std::string> FrameGrabber_nws_ros2_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("period");
    params.push_back("node_name");
    params.push_back("topic_name");
    params.push_back("frame_id");
    return params;
}


bool      FrameGrabber_nws_ros2_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
    }

    //Parser of parameter node_name
    {
        if (config.check("node_name"))
        {
            m_node_name = config.find("node_name").asString();
            yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Parameter 'node_name' using value:" << m_node_name;
        }
        else
        {
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Mandatory parameter 'node_name' not found!";
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Description of the parameter: set the name for ROS node";
            return false;
        }
        prop_check.unput("node_name");
    }

    //Parser of parameter topic_name
    {
        if (config.check("topic_name"))
        {
            m_topic_name = config.find("topic_name").asString();
            yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Parameter 'topic_name' using value:" << m_topic_name;
        }
        else
        {
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Mandatory parameter 'topic_name' not found!";
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Description of the parameter: set the name for ROS topic";
            return false;
        }
        prop_check.unput("topic_name");
    }

    //Parser of parameter frame_id
    {
        if (config.check("frame_id"))
        {
            m_frame_id = config.find("frame_id").asString();
            yCInfo(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Parameter 'frame_id' using value:" << m_frame_id;
        }
        else
        {
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Mandatory parameter 'frame_id' not found!";
            yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "Description of the parameter: set the name for the reference frame";
            return false;
        }
        prop_check.unput("frame_id");
    }

    /*
    //This code check if the user set some parameter which are not check by the parser
    //If the parser is set in strict mode, this will generate an error
    if (prop_check.size() > 0)
    {
        bool extra_params_found = false;
        for (auto it=prop_check.begin(); it!=prop_check.end(); it++)
        {
            if (m_parser_is_strict)
            {
                yCError(FrameGrabber_nws_ros2ParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FrameGrabber_nws_ros2ParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
            }
        }

       if (m_parser_is_strict && extra_params_found)
       {
           return false;
       }
    }
    */
    return true;
}


std::string      FrameGrabber_nws_ros2_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FrameGrabber_nws_ros2\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'period': refresh period of the broadcasted values in s\n");
    doc = doc + std::string("'node_name': set the name for ROS node\n");
    doc = doc + std::string("'topic_name': set the name for ROS topic\n");
    doc = doc + std::string("'frame_id': set the name for the reference frame\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device frameGrabber_nws_ros2 --period 0.02 --node_name <mandatory_value> --topic_name <mandatory_value> --frame_id <mandatory_value>\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device frameGrabber_nws_ros2 --node_name <mandatory_value> --topic_name <mandatory_value> --frame_id <mandatory_value>\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
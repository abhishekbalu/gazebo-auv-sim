#pragma once

#include <string>

#include <gazebo/msgs/msgs.hh>

#include <msg_regul.h>
#include <msg_robosub.h>
#include <msg_navig.h>

#include <regul.pb.h>
#include <navig.pb.h>
#include <camera.pb.h>

#include "transport_pipe.h"

template<class RecieveMsgType, class ForwardMsgType, class Consts>
struct IPCToGazeboPolicy {
    typedef RecieveMsgType RecieveMsg;
    typedef IPCReciever<RecieveMsg, Consts> RecieverClass;

    typedef ForwardMsgType ForwardMsg;
    typedef GazeboForwarder<ForwardMsg, Consts> ForwarderClass;
};

template<class RecieveMsgType, class ForwardMsgType, class Consts>
struct GazeboToIPCPolicy {
    typedef RecieveMsgType RecieveMsg;
    typedef GazeboReciever<RecieveMsg, Consts> RecieverClass;

    typedef ForwardMsgType ForwardMsg;
    typedef IPCForwarder<ForwardMsg, Consts> ForwarderClass;
};

struct RegulConsts {
    const char* IPC_NAME = MSG_REGUL_NAME;
    const char* IPC_FORMAT = MSG_REGUL_FORMAT;
    const std::string TOPIC = "~/regul";
};
using  RegulPolicy = IPCToGazeboPolicy<MSG_REGUL_TYPE, msgs::Regul, RegulConsts>;

struct CameraConsts {
    const char* IPC_NAME = MSG_JPEG_VIDEO_FRAME_NAME;
    const char* IPC_FORMAT = MSG_JPEG_VIDEO_FRAME_FORMAT;
    const std::string TOPIC = "~/camera";
};
using CameraPolicy = GazeboToIPCPolicy<msgs::Camera, MSG_JPEG_VIDEO_FRAME, CameraConsts>;

struct NavigConsts {
    const char* IPC_NAME = MSG_NAVIG_NAME;
    const char* IPC_FORMAT = MSG_NAVIG_FORMAT;
    const std::string TOPIC = "~/navig";
};
using NavigPolicy = GazeboToIPCPolicy<msgs::Navig, MSG_NAVIG_TYPE, NavigConsts>;


cmake_minimum_required(VERSION 3.10)

project(QtClientDemo)

# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 11)

# 设置目标
set(TARGET QtClientDemo)

# Qt 库
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

set(BASE_DIR ../../src)
file(GLOB_RECURSE H_FILES ${BASE_DIR}/*.h)
file(GLOB_RECURSE CPP_FILES ${BASE_DIR}/*.cpp)
file(GLOB_RECURSE UI_FILES ${BASE_DIR}/*.ui)
set(HEADERS ${H_FILES})
set(SOURCES ${CPP_FILES})
set(FORMS ${UI_FILES})
# # 头文件
# set(HEADERS
#     ../../src/MainWindow/DeviceTree/DeviceAttr/deviceattr.h
#     ../../src/MainWindow/DeviceTree/ChannelAttr/channelattr.h
#     ../../src/MainWindow/DeviceTree/AddNode/addnode.h
#     ../../src/MainWindow/DeviceTree/treemodel.h
#     ../../src/MainWindow/DeviceTree/treeitem.h
#     ../../src/MainWindow/DeviceTree/devicedata.h
#     ../../src/MainWindow/DeviceTree/channeldata.h
#     ../../src/MainWindow/LogAlarm/AlarmTable/alarmtable.h
#     ../../src/MainWindow/LogAlarm/LogTable/logtable.h
#     ../../src/RealPlay/realplay.h
#     ../../src/RealPlay/PTZ/PtzCruise/ptzcruise.h
#     ../../src/RealPlay/PTZ/PtzPreset/ptzpreset.h
#     ../../src/PlayBack/playback.h
#     ../../src/ManageDevice/Timing/timing.h
#     ../../src/ManageDevice/Update/remoteupdate.h
#     ../../src/ManageDevice/Format/formatdisk.h
#     ../../src/ManageDevice/Reboot/rebootdevice.h
#     ../../src/ManageDevice/Shutdown/shutdowndevice.h
#     ../../src/ManageDevice/LogSearch/logsearch.h
#     ../../src/ManageDevice/DeviceState/devicestate.h
#     ../../src/ManageDevice/Reset/resetdevice.h
#     ../../src/OtherFunc/Deployment/deploy.h
#     ../../src/OtherFunc/DevicePan/devicepan.h
#     ../../src/OtherFunc/ImportConfig/importconfig.h
#     ../../src/OtherFunc/SerialTransfer/serialtransfer.h
#     ../../src/OtherFunc/AudioBroadcast/audiobroadcast.h
#     ../../src/OtherFunc/AudioIntercom/audiointercom.h
#     ../../src/OtherFunc/AudioTransfer/audiotransfer.h
#     ../../src/ExitModule/exitdemo.h
#     ../../src/qtclientdemo.h
#     ../../src/ParaConfig/configure_params/PublicFuc/publicfuc.h
#     ../../src/ParaConfig/configure_params/cconfigureparams.h
#     ../../src/RealPlay/FramePlayWnd.h
#     ../../src/Public/DemoPublic.h
# )

# set(PARA_BASE_DIR ../../src/ParaConfig/configure_params)
# file(GLOB_RECURSE PARA_CPP_FILES ${PARA_BASE_DIR}/*.cpp)
# # 源文件
# set(SOURCES
#     ../../src/MainWindow/DeviceTree/DeviceAttr/deviceattr.cpp
#     ../../src/MainWindow/DeviceTree/ChannelAttr/channelattr.cpp
#     ../../src/MainWindow/DeviceTree/AddNode/addnode.cpp
#     ../../src/MainWindow/DeviceTree/treemodel.cpp
#     ../../src/MainWindow/DeviceTree/treeitem.cpp
#     ../../src/MainWindow/DeviceTree/devicedata.cpp
#     ../../src/MainWindow/DeviceTree/channeldata.cpp
#     ../../src/MainWindow/LogAlarm/AlarmTable/alarmtable.cpp
#     ../../src/MainWindow/LogAlarm/LogTable/logtable.cpp
#     ../../src/RealPlay/realplay.cpp
#     ../../src/RealPlay/PTZ/PtzCruise/ptzcruise.cpp
#     ../../src/RealPlay/PTZ/PtzPreset/ptzpreset.cpp
#     ../../src/PlayBack/playback.cpp
#     ../../src/ManageDevice/Timing/timing.cpp
#     ../../src/ManageDevice/Update/remoteupdate.cpp
#     ../../src/ManageDevice/Format/formatdisk.cpp
#     ../../src/ManageDevice/Reboot/rebootdevice.cpp
#     ../../src/ManageDevice/Shutdown/shutdowndevice.cpp
#     ../../src/ManageDevice/LogSearch/logsearch.cpp
#     ../../src/ManageDevice/DeviceState/devicestate.cpp
#     ../../src/ManageDevice/Reset/resetdevice.cpp
#     ../../src/OtherFunc/Deployment/deploy.cpp
#     ../../src/OtherFunc/DevicePan/devicepan.cpp
#     ../../src/OtherFunc/ImportConfig/importconfig.cpp
#     ../../src/OtherFunc/SerialTransfer/serialtransfer.cpp
#     ../../src/OtherFunc/AudioBroadcast/audiobroadcast.cpp
#     ../../src/OtherFunc/AudioIntercom/audiointercom.cpp
#     ../../src/OtherFunc/AudioTransfer/audiotransfer.cpp
#     ../../src/ExitModule/exitdemo.cpp
#     ../../src/main.cpp
#     ../../src/qtclientdemo.cpp
#     ../../src/ParaConfig/configure_params/PublicFuc/publicfuc.cpp
#     ../../src/ParaConfig/configure_params/cconfigureparams.cpp
#     # ${PARA_CPP_FILES}
#     ../../src/ParaConfig/configure_params/RemoteParams/cremoteparams.cpp
#     ../../src/ParaConfig/configure_params/IPParams/cipparams.cpp
#     ../../src/ParaConfig/configure_params/HardDiskParams/charddiskparams.cpp
#     ../../src/ParaConfig/configure_params/RemoteParams/ExceptionParams/exceptionparams.cpp
#     ../../src/ParaConfig/configure_params/RemoteParams/NetParams/czonedst.cpp
#     ../../src/ParaConfig/configure_params/RemoteParams/NetParams/crtspparams.cpp
#     ../../src/ParaConfig/configure_params/RemoteParams/NetParams/ccompressaudio.cpp
#     ../../src/RealPlay/FramePlayWnd.cpp
# )

# file(GLOB_RECURSE PARA_UI_FILES ${PARA_BASE_DIR}/*.ui)
# # UI 文件
# set(FORMS
#     ../../src/MainWindow/DeviceTree/DeviceAttr/deviceattr.ui
#     ../../src/MainWindow/DeviceTree/ChannelAttr/channelattr.ui
#     ../../src/MainWindow/DeviceTree/AddNode/addnode.ui
#     ../../src/MainWindow/LogAlarm/AlarmTable/alarmtable.ui
#     ../../src/MainWindow/LogAlarm/LogTable/logtable.ui
#     ../../src/RealPlay/realplay.ui
#     ../../src/RealPlay/PTZ/PtzCruise/ptzcruise.ui
#     ../../src/RealPlay/PTZ/PtzPreset/ptzpreset.ui
#     ../../src/PlayBack/playback.ui
#     ../../src/ManageDevice/Timing/timing.ui
#     ../../src/ManageDevice/Update/remoteupdate.ui
#     ../../src/ManageDevice/Format/formatdisk.ui
#     ../../src/ManageDevice/Reboot/rebootdevice.ui
#     ../../src/ManageDevice/Shutdown/shutdowndevice.ui
#     ../../src/ManageDevice/LogSearch/logsearch.ui
#     ../../src/ManageDevice/DeviceState/devicestate.ui
#     ../../src/ManageDevice/Reset/resetdevice.ui
#     ../../src/OtherFunc/Deployment/deploy.ui
#     ../../src/OtherFunc/DevicePan/devicepan.ui
#     ../../src/OtherFunc/ImportConfig/importconfig.ui
#     ../../src/OtherFunc/SerialTransfer/serialtransfer.ui
#     ../../src/OtherFunc/AudioBroadcast/audiobroadcast.ui
#     ../../src/OtherFunc/AudioIntercom/audiointercom.ui
#     ../../src/OtherFunc/AudioTransfer/audiotransfer.ui
#     ../../src/ExitModule/exitdemo.ui
#     ../../src/qtclientdemo.ui
#     ${PARA_UI_FILES}
#     ../../src/RealPlay/FramePlayWnd.ui
# )

# 包含路径
include_directories(
    ../../src/MainWindow/DeviceTree/
    ../../src/MainWindow/DeviceTree/AddNode/
    ../../src/MainWindow/DeviceTree/DeviceAttr/
    ../../src/MainWindow/LogAlarm/AlarmTable/
    ../../src/MainWindow/LogAlarm/LogTable/
    ../../src/MainWindow/DeviceTree/ChannelAttr/
    ../../src/RealPlay/
    ../../src/RealPlay/PTZ/PtzCruise/
    ../../src/RealPlay/PTZ/PtzPreset/
    ../../src/PlayBack/
    ../../src/ManageDevice/Timing/
    ../../src/ManageDevice/Update/
    ../../src/ManageDevice/Format/
    ../../src/ManageDevice/Reboot/
    ../../src/ManageDevice/Shutdown/
    ../../src/ManageDevice/LogSearch/
    ../../src/ManageDevice/DeviceState/
    ../../src/ManageDevice/Reset/
    ../../src/OtherFunc/Deployment/
    ../../src/OtherFunc/DevicePan/
    ../../src/OtherFunc/ImportConfig/
    ../../src/OtherFunc/SerialTransfer/
    ../../src/OtherFunc/AudioBroadcast/
    ../../src/OtherFunc/AudioIntercom/
    ../../src/OtherFunc/AudioTransfer/
    ../../src/ExitModule/
    ../../src/ParaConfig/configure_params/
    ../../src/ParaConfig/configure_params/RemoteParams
    ../../src/ParaConfig/configure_params/RemoteParams/NetParams
    ../../src/ParaConfig/configure_params/RemoteParams/ChannelParams
    ../../src/ParaConfig/configure_params/RemoteParams/UserParams
    ../../src/ParaConfig/configure_params/RemoteParams/ExceptionParams
    ../../src/ParaConfig/configure_params/RemoteParams/SerialParams
    ../../src/ParaConfig/configure_params/RemoteParams/AlarmParams
    ../../src/ParaConfig/configure_params/RemoteParams/ATMParams
    ../../src/ParaConfig/configure_params/PublicFuc
    ../../src/ParaConfig/configure_params/IPParams
    ../../src/ParaConfig/configure_params/HardDiskParams
    ../../src/
    ../../includeCn
    ../../src/Public
    ${CMAKE_BINARY_DIR}
)

# 设置资源文件
set(RESOURCES "../../src/Player.qrc")

qt5_wrap_cpp(CPP_WRAP_FILES ${HEADERS})
qt5_wrap_ui(UI_WRAP_FILES ${FORMS})

# 定义库的路径
# set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/../lib")
set(LIBRARY_DIR 
    "${CMAKE_SOURCE_DIR}/../lib"
    "${CMAKE_SOURCE_DIR}/../lib/HCNetSDKCom"
)
# 将库目录添加到链接器的搜索路径中
# 指定 rpath（运行时库搜索路径）
# set(CMAKE_INSTALL_RPATH "/home/shuai/HK/QtDemo/Linux64/lib:/home/shuai/HK/QtDemo/Linux64/lib/HCNetSDKCom")
link_directories(${LIBRARY_DIR})

# 添加可执行文件
add_executable(${TARGET} ${CPP_WRAP_FILES} ${SOURCES} ${UI_WRAP_FILES} ${RESOURCES})

# 指定输出目录
set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin
)

# 链接库
target_link_libraries(${TARGET} 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::OpenGL
    AudioRender
    hcnetsdk
    PlayCtrl
    SuperRender
)

# 翻译文件
set(TRANSLATIONS ../../translation/QtDemo_zh_CN.ts)
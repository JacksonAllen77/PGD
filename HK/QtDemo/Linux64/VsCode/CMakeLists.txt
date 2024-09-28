cmake_minimum_required(VERSION 3.10)

project(QtClientDemo)

set(CMAKE_CXX_STANDARD 11)

# 设置目标
set(TARGET QtClientDemo)

set(CMAKE_PREFIX_PATH "/opt/Qt5.12.9/5.12.9/gcc_64")
# Qt 库
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

set(BASE_DIR ../../src)
file(GLOB_RECURSE CPP_FILES ${BASE_DIR}/*.cpp)
file(GLOB_RECURSE H_FILES ${BASE_DIR}/*.h)
file(GLOB_RECURSE UI_FILES ${BASE_DIR}/*.ui)
set(SOURCES ${CPP_FILES})
set(HEADERS ${H_FILES})
set(FORMS ${UI_FILES})

# 这句相当于是在include_directories中添加了${CMAKE_BINARY_DIR}
set(CMAKE_INCLUDE_CURRENT_DIR ON)

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
    # ${CMAKE_BINARY_DIR}
)

# 资源文件
set(RESOURCES "../../src/Player.qrc")

qt5_wrap_cpp(HEADERS_MOC ${HEADERS})
qt5_wrap_ui(FORMS_HEADERS ${FORMS})
qt5_add_resources(RESOURCES_RCC ${RESOURCES})

# 设置动态库的查找目录link_directories一定要在add_executable之前
set(LIBRARY_DIR 
    "${CMAKE_SOURCE_DIR}/../lib"
    "${CMAKE_SOURCE_DIR}/../lib/HCNetSDKCom"
)
link_directories(${LIBRARY_DIR})

# 添加可执行文件
add_executable(${TARGET} ${SOURCES} ${HEADERS_MOC} ${FORMS_HEADERS} ${RESOURCES_RCC})
# 指定输出目录
set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib
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

find_package(Qt5 COMPONENTS LinguistTools REQUIRED)

# 初始化要使用的列表
set(TS_FILES)
set(QM_FILES)

# 将要生成的翻译文件添加到列表中
list(APPEND TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../translation/QtDemo_zh_CN.ts)

# 设置翻译文件的生成路径，如果不指定就会生成在CMakeFiles的目录里
set_source_files_properties(${TS_FILES}
    PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# 创建翻译的最关键一步
qt5_create_translation(QM_FILES ${TS_FILES} ${PROJECT_SOURCES})

# 添加更新翻译的目标
add_custom_target(lupdate_task DEPENDS ${TS_FILES})
add_custom_target(lrelease_task DEPENDS ${QM_FILES})

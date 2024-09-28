cmake_minimum_required(VERSION 3.5)

project(TEST LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET test)

file(GLOB_RECURSE CPP_FILES ./src/*.cpp)
file(GLOB_RECURSE H_FILES ./include/*.h)
file(GLOB_RECURSE UI_FILES ./ui/*.ui)
file(GLOB_RECURSE QRC_FILES ./qrc/*.qrc)
set(SOURCES ${CPP_FILES})
set(HEADERS ${H_FILES})
set(FORMS ${UI_FILES})
set(RESOURCES ${QRC_FILES})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_wrap_cpp(HEADERS_MOC ${HEADERS})
qt5_wrap_ui(FORMS_HEADERS ${FORMS})
qt5_add_resources(RESOURCES_RCC ${RESOURCES})

include_directories(./include)

add_executable(${TARGET}
    ${SOURCES} 
    ${HEADERS_MOC} 
    ${FORMS_HEADERS}
    ${RESOURCES_RCC}
)

target_link_libraries(${TARGET} PRIVATE Qt5::Widgets)
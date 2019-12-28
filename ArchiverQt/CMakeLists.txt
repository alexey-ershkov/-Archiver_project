cmake_minimum_required(VERSION 3.5)

project(ArchiverQt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(/headers)
include_directories(../lib_headers)
add_executable(ArchiverQt main.cpp qml.qrc QtView.cpp)
add_subdirectory(../ build)


target_compile_definitions(ArchiverQt
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ArchiverQt
  PRIVATE Qt5::Core Qt5::Quick  Qt5::Widgets ArchiverEngine)



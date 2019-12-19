cmake_minimum_required(VERSION 3.5)

project(ArchiverQt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
set(magic_DIR /usr/local/Cellar/libmagic/5.37)


include(FindPackageHandleStandardArgs)

include_directories(${MAGIC_INCLUDE_DIR})

include_directories(../lib_headers)
add_executable(ArchiverQt main.cpp qml.qrc)
add_subdirectory(../ build)


target_compile_definitions(ArchiverQt
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ArchiverQt
  PRIVATE Qt5::Core Qt5::Quick ArchiverEngine)



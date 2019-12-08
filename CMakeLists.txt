cmake_minimum_required(VERSION 3.8)
project(Archiver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(lib_headers/)

set(ArchiveLib Presenter.cpp View.cpp Show.cpp Archive.cpp Dearchive.cpp)

add_library(ArchiverEngine STATIC ${ArchiveLib})

add_executable(ArchiveConsole main.cpp)
target_link_libraries(ArchiveConsole ArchiverEngine)


add_executable(UnitTests GTest.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(UnitTests ArchiverEngine)

#QT5


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(QTTest mainQT.cpp)

target_link_libraries(QTTest Qt5::Widgets)


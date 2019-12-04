cmake_minimum_required(VERSION 3.8)
project(Archiver)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(headers/)

add_executable(ArchiverEngine main.cpp Presenter.cpp View.cpp Show.cpp Archive.cpp Dearchive.cpp)



add_executable(UnitTests GTest.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)
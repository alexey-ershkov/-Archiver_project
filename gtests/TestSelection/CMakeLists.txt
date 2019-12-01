cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(
        ../../
        ${GTEST_INCLUDE_DIRS}
)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests TestSelection.cpp  ../../Huffman.cpp ../../Input.cpp ../../Output.cpp ../../Algorithm.cpp ../../Selection.cpp ../../LZW.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
cmake_minimum_required(VERSION 3.8)
project(Haffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Haffman Huffman.cpp Huffman.h main.cpp)
add_executable(Test main.cpp Huffman.h)
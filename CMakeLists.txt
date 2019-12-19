cmake_minimum_required(VERSION 3.3)

project(Archiver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
set(magic_DIR /usr/local/Cellar/libmagic/5.37)


include(FindPackageHandleStandardArgs)

include_directories(${MAGIC_INCLUDE_DIR})


find_package (LibMagic REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(lib_headers/)


set(ArchiveLib Algorithm.cpp Archiver.cpp ArchiveFile.cpp TypeIdentifier.cpp Input.cpp LZW.cpp Output.cpp Selection.cpp Huffman.cpp Presenter.cpp View.cpp Show.cpp Archive.cpp Dearchive.cpp )

add_library(ArchiverEngine STATIC ${ArchiveLib})
target_link_libraries(ArchiverEngine ${LIBMAGIC_LIBRARIES})


add_executable(ArchiveConsole main.cpp)
target_link_libraries(ArchiveConsole ArchiverEngine)


add_executable(UnitTests GTest.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(UnitTests ArchiverEngine)





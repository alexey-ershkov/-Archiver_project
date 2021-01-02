cmake_minimum_required(VERSION 3.8)
project(Archiver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
set(magic_DIR /usr/local/Cellar/libmagic/5.37)


include(FindPackageHandleStandardArgs)

include_directories(${MAGIC_INCLUDE_DIR})


find_package (LibMagic REQUIRED)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(lib_headers/)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(ArchiveLib Presenter.cpp ConsoleView.cpp Show.cpp Archive.cpp Dearchive.cpp Algorithm.cpp CodeWriter.cpp
        CodeReader.cpp EncoderDictionary.cpp Huffman.cpp Input.cpp LZW.cpp Output.cpp Selection.cpp
        ArchiveFileWriter.cpp ArchiveFileReader.cpp lib_headers/IGetFileSize.h buff.cpp Archiver.cpp TypeIdentifier.cpp)
add_library(ArchiverEngine STATIC ${ArchiveLib})
target_link_libraries(ArchiverEngine PRIVATE ${LIBMAGIC_LIBRARIES})

add_executable(ArchiveConsole main.cpp)
target_link_libraries(ArchiveConsole  PRIVATE Qt5::Core Qt5::Quick Qt5::Widgets ArchiverEngine)


add_executable(UnitTests GTest.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(UnitTests ArchiverEngine)






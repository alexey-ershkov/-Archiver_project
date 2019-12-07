cmake_minimum_required(VERSION 3.8)
project(Archiver CXX)


set(CMAKE_CXX_STANDARD 17)

add_subdirectory(boost-cmake)

add_executable(Archiver
        Archiver.hpp TypeIdentifier.hpp
        Archiver.cpp TypeIdentifier.cpp
        Output.cpp   Input.cpp
        Output.h     Input.h
        IOutputStream.h
        IInputStream.h  ArchiveFile.hpp
        IGetFileSize.h  ArchiveFile.cpp

        )

target_link_libraries(Archiver PUBLIC Boost::filesystem)
target_link_libraries(Archiver PUBLIC Boost::boost)
target_link_libraries(Archiver PUBLIC magic)

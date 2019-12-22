cmake_minimum_required(VERSION 3.8)
project(Archiver CXX)


set(CMAKE_CXX_STANDARD 17)


add_executable(Archiver
        Archiver.hpp TypeIdentifier.hpp
        Archiver.cpp TypeIdentifier.cpp
        Output.cpp   Input.cpp
        Output.h     Input.h
        IOutputStream.h
        IInputStream.h ArchiveFileWriter.hpp
        IGetFileSize.h ArchiveFileWriter.cpp
        ArchiveFileReader.hpp ArchiveFileReader.cpp

        main.cpp

        )
add_executable(TEST buff.cpp)

target_link_libraries(Archiver PUBLIC magic)

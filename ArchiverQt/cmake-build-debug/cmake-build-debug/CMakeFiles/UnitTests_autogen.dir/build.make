# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug

# Utility rule file for UnitTests_autogen.

# Include the progress variables for this target.
include cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/progress.make

cmake-build-debug/CMakeFiles/UnitTests_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target UnitTests"
	cd /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/cmake-build-debug && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E cmake_autogen /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/AutogenInfo.cmake Debug

UnitTests_autogen: cmake-build-debug/CMakeFiles/UnitTests_autogen
UnitTests_autogen: cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/build.make

.PHONY : UnitTests_autogen

# Rule to build all files generated by this target.
cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/build: UnitTests_autogen

.PHONY : cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/build

cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/clean:
	cd /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/cmake-build-debug && $(CMAKE_COMMAND) -P CMakeFiles/UnitTests_autogen.dir/cmake_clean.cmake
.PHONY : cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/clean

cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/depend:
	cd /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt /Users/farcoad/Documents/Deep_C++/Archiver /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/cmake-build-debug /Users/farcoad/Documents/Deep_C++/Archiver/ArchiverQt/cmake-build-debug/cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cmake-build-debug/CMakeFiles/UnitTests_autogen.dir/depend


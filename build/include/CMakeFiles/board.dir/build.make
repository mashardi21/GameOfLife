# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hippo/Development/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hippo/Development/GameOfLife/build

# Include any dependencies generated for this target.
include include/CMakeFiles/board.dir/depend.make

# Include the progress variables for this target.
include include/CMakeFiles/board.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/board.dir/flags.make

include/CMakeFiles/board.dir/board.cpp.o: include/CMakeFiles/board.dir/flags.make
include/CMakeFiles/board.dir/board.cpp.o: ../include/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hippo/Development/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/board.dir/board.cpp.o"
	cd /home/hippo/Development/GameOfLife/build/include && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/board.dir/board.cpp.o -c /home/hippo/Development/GameOfLife/include/board.cpp

include/CMakeFiles/board.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board.dir/board.cpp.i"
	cd /home/hippo/Development/GameOfLife/build/include && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hippo/Development/GameOfLife/include/board.cpp > CMakeFiles/board.dir/board.cpp.i

include/CMakeFiles/board.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board.dir/board.cpp.s"
	cd /home/hippo/Development/GameOfLife/build/include && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hippo/Development/GameOfLife/include/board.cpp -o CMakeFiles/board.dir/board.cpp.s

# Object files for target board
board_OBJECTS = \
"CMakeFiles/board.dir/board.cpp.o"

# External object files for target board
board_EXTERNAL_OBJECTS =

include/libboard.a: include/CMakeFiles/board.dir/board.cpp.o
include/libboard.a: include/CMakeFiles/board.dir/build.make
include/libboard.a: include/CMakeFiles/board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hippo/Development/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libboard.a"
	cd /home/hippo/Development/GameOfLife/build/include && $(CMAKE_COMMAND) -P CMakeFiles/board.dir/cmake_clean_target.cmake
	cd /home/hippo/Development/GameOfLife/build/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/board.dir/build: include/libboard.a

.PHONY : include/CMakeFiles/board.dir/build

include/CMakeFiles/board.dir/clean:
	cd /home/hippo/Development/GameOfLife/build/include && $(CMAKE_COMMAND) -P CMakeFiles/board.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/board.dir/clean

include/CMakeFiles/board.dir/depend:
	cd /home/hippo/Development/GameOfLife/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hippo/Development/GameOfLife /home/hippo/Development/GameOfLife/include /home/hippo/Development/GameOfLife/build /home/hippo/Development/GameOfLife/build/include /home/hippo/Development/GameOfLife/build/include/CMakeFiles/board.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/board.dir/depend


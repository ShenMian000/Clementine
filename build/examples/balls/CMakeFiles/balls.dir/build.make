# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sms/Clementine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sms/Clementine/build

# Include any dependencies generated for this target.
include examples/balls/CMakeFiles/balls.dir/depend.make

# Include the progress variables for this target.
include examples/balls/CMakeFiles/balls.dir/progress.make

# Include the compile flags for this target's objects.
include examples/balls/CMakeFiles/balls.dir/flags.make

examples/balls/CMakeFiles/balls.dir/main.cpp.o: examples/balls/CMakeFiles/balls.dir/flags.make
examples/balls/CMakeFiles/balls.dir/main.cpp.o: ../examples/balls/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sms/Clementine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/balls/CMakeFiles/balls.dir/main.cpp.o"
	cd /home/sms/Clementine/build/examples/balls && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/balls.dir/main.cpp.o -c /home/sms/Clementine/examples/balls/main.cpp

examples/balls/CMakeFiles/balls.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/main.cpp.i"
	cd /home/sms/Clementine/build/examples/balls && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sms/Clementine/examples/balls/main.cpp > CMakeFiles/balls.dir/main.cpp.i

examples/balls/CMakeFiles/balls.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/main.cpp.s"
	cd /home/sms/Clementine/build/examples/balls && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sms/Clementine/examples/balls/main.cpp -o CMakeFiles/balls.dir/main.cpp.s

# Object files for target balls
balls_OBJECTS = \
"CMakeFiles/balls.dir/main.cpp.o"

# External object files for target balls
balls_EXTERNAL_OBJECTS =

examples/balls/balls: examples/balls/CMakeFiles/balls.dir/main.cpp.o
examples/balls/balls: examples/balls/CMakeFiles/balls.dir/build.make
examples/balls/balls: ../lib/libclementine.a
examples/balls/balls: examples/balls/CMakeFiles/balls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sms/Clementine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable balls"
	cd /home/sms/Clementine/build/examples/balls && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/balls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/balls/CMakeFiles/balls.dir/build: examples/balls/balls

.PHONY : examples/balls/CMakeFiles/balls.dir/build

examples/balls/CMakeFiles/balls.dir/clean:
	cd /home/sms/Clementine/build/examples/balls && $(CMAKE_COMMAND) -P CMakeFiles/balls.dir/cmake_clean.cmake
.PHONY : examples/balls/CMakeFiles/balls.dir/clean

examples/balls/CMakeFiles/balls.dir/depend:
	cd /home/sms/Clementine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sms/Clementine /home/sms/Clementine/examples/balls /home/sms/Clementine/build /home/sms/Clementine/build/examples/balls /home/sms/Clementine/build/examples/balls/CMakeFiles/balls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/balls/CMakeFiles/balls.dir/depend

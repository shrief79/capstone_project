# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/shrief/Desktop/FINAL_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shrief/Desktop/FINAL_project/build

# Include any dependencies generated for this target.
include CMakeFiles/daemon_logger.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/daemon_logger.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/daemon_logger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/daemon_logger.dir/flags.make

CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o: CMakeFiles/daemon_logger.dir/flags.make
CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o: ../logger/simpleLogger.cpp
CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o: CMakeFiles/daemon_logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/FINAL_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o -MF CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o.d -o CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o -c /home/shrief/Desktop/FINAL_project/logger/simpleLogger.cpp

CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/FINAL_project/logger/simpleLogger.cpp > CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.i

CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/FINAL_project/logger/simpleLogger.cpp -o CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.s

CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o: CMakeFiles/daemon_logger.dir/flags.make
CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o: ../logger/config_lib.cpp
CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o: CMakeFiles/daemon_logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/FINAL_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o -MF CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o.d -o CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o -c /home/shrief/Desktop/FINAL_project/logger/config_lib.cpp

CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/FINAL_project/logger/config_lib.cpp > CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.i

CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/FINAL_project/logger/config_lib.cpp -o CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.s

CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o: CMakeFiles/daemon_logger.dir/flags.make
CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o: ../socket/rpi.cpp
CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o: CMakeFiles/daemon_logger.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/FINAL_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o -MF CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o.d -o CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o -c /home/shrief/Desktop/FINAL_project/socket/rpi.cpp

CMakeFiles/daemon_logger.dir/socket/rpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daemon_logger.dir/socket/rpi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/FINAL_project/socket/rpi.cpp > CMakeFiles/daemon_logger.dir/socket/rpi.cpp.i

CMakeFiles/daemon_logger.dir/socket/rpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daemon_logger.dir/socket/rpi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/FINAL_project/socket/rpi.cpp -o CMakeFiles/daemon_logger.dir/socket/rpi.cpp.s

# Object files for target daemon_logger
daemon_logger_OBJECTS = \
"CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o" \
"CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o" \
"CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o"

# External object files for target daemon_logger
daemon_logger_EXTERNAL_OBJECTS =

daemon_logger: CMakeFiles/daemon_logger.dir/logger/simpleLogger.cpp.o
daemon_logger: CMakeFiles/daemon_logger.dir/logger/config_lib.cpp.o
daemon_logger: CMakeFiles/daemon_logger.dir/socket/rpi.cpp.o
daemon_logger: CMakeFiles/daemon_logger.dir/build.make
daemon_logger: libmsgque_lib.so
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
daemon_logger: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
daemon_logger: CMakeFiles/daemon_logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shrief/Desktop/FINAL_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable daemon_logger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/daemon_logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/daemon_logger.dir/build: daemon_logger
.PHONY : CMakeFiles/daemon_logger.dir/build

CMakeFiles/daemon_logger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/daemon_logger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/daemon_logger.dir/clean

CMakeFiles/daemon_logger.dir/depend:
	cd /home/shrief/Desktop/FINAL_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shrief/Desktop/FINAL_project /home/shrief/Desktop/FINAL_project /home/shrief/Desktop/FINAL_project/build /home/shrief/Desktop/FINAL_project/build /home/shrief/Desktop/FINAL_project/build/CMakeFiles/daemon_logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/daemon_logger.dir/depend


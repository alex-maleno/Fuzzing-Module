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
CMAKE_SOURCE_DIR = /exercise3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /exercise3/afl-build

# Include any dependencies generated for this target.
include CMakeFiles/drone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/drone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/drone.dir/flags.make

CMakeFiles/drone.dir/main.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/exercise3/afl-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/drone.dir/main.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/main.cpp.o -c /exercise3/main.cpp

CMakeFiles/drone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/main.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /exercise3/main.cpp > CMakeFiles/drone.dir/main.cpp.i

CMakeFiles/drone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/main.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /exercise3/main.cpp -o CMakeFiles/drone.dir/main.cpp.s

CMakeFiles/drone.dir/maneuvers.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/maneuvers.cpp.o: ../maneuvers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/exercise3/afl-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/drone.dir/maneuvers.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/maneuvers.cpp.o -c /exercise3/maneuvers.cpp

CMakeFiles/drone.dir/maneuvers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/maneuvers.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /exercise3/maneuvers.cpp > CMakeFiles/drone.dir/maneuvers.cpp.i

CMakeFiles/drone.dir/maneuvers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/maneuvers.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /exercise3/maneuvers.cpp -o CMakeFiles/drone.dir/maneuvers.cpp.s

CMakeFiles/drone.dir/specs.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/specs.cpp.o: ../specs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/exercise3/afl-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/drone.dir/specs.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/specs.cpp.o -c /exercise3/specs.cpp

CMakeFiles/drone.dir/specs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/specs.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /exercise3/specs.cpp > CMakeFiles/drone.dir/specs.cpp.i

CMakeFiles/drone.dir/specs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/specs.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /exercise3/specs.cpp -o CMakeFiles/drone.dir/specs.cpp.s

CMakeFiles/drone.dir/sys_status.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/sys_status.cpp.o: ../sys_status.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/exercise3/afl-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/drone.dir/sys_status.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/sys_status.cpp.o -c /exercise3/sys_status.cpp

CMakeFiles/drone.dir/sys_status.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/sys_status.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /exercise3/sys_status.cpp > CMakeFiles/drone.dir/sys_status.cpp.i

CMakeFiles/drone.dir/sys_status.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/sys_status.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /exercise3/sys_status.cpp -o CMakeFiles/drone.dir/sys_status.cpp.s

# Object files for target drone
drone_OBJECTS = \
"CMakeFiles/drone.dir/main.cpp.o" \
"CMakeFiles/drone.dir/maneuvers.cpp.o" \
"CMakeFiles/drone.dir/specs.cpp.o" \
"CMakeFiles/drone.dir/sys_status.cpp.o"

# External object files for target drone
drone_EXTERNAL_OBJECTS =

drone: CMakeFiles/drone.dir/main.cpp.o
drone: CMakeFiles/drone.dir/maneuvers.cpp.o
drone: CMakeFiles/drone.dir/specs.cpp.o
drone: CMakeFiles/drone.dir/sys_status.cpp.o
drone: CMakeFiles/drone.dir/build.make
drone: CMakeFiles/drone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/exercise3/afl-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable drone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/drone.dir/build: drone

.PHONY : CMakeFiles/drone.dir/build

CMakeFiles/drone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/drone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/drone.dir/clean

CMakeFiles/drone.dir/depend:
	cd /exercise3/afl-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /exercise3 /exercise3 /exercise3/afl-build /exercise3/afl-build /exercise3/afl-build/CMakeFiles/drone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/drone.dir/depend

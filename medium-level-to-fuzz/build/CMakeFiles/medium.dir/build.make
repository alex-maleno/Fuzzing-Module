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
CMAKE_SOURCE_DIR = "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build"

# Include any dependencies generated for this target.
include CMakeFiles/medium.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/medium.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/medium.dir/flags.make

CMakeFiles/medium.dir/airplane_object.cpp.o: CMakeFiles/medium.dir/flags.make
CMakeFiles/medium.dir/airplane_object.cpp.o: ../airplane_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/medium.dir/airplane_object.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/medium.dir/airplane_object.cpp.o -c "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/airplane_object.cpp"

CMakeFiles/medium.dir/airplane_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/medium.dir/airplane_object.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/airplane_object.cpp" > CMakeFiles/medium.dir/airplane_object.cpp.i

CMakeFiles/medium.dir/airplane_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/medium.dir/airplane_object.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/airplane_object.cpp" -o CMakeFiles/medium.dir/airplane_object.cpp.s

CMakeFiles/medium.dir/main.cpp.o: CMakeFiles/medium.dir/flags.make
CMakeFiles/medium.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/medium.dir/main.cpp.o"
	/AFLplusplus/afl-clang-lto++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/medium.dir/main.cpp.o -c "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/main.cpp"

CMakeFiles/medium.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/medium.dir/main.cpp.i"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/main.cpp" > CMakeFiles/medium.dir/main.cpp.i

CMakeFiles/medium.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/medium.dir/main.cpp.s"
	/AFLplusplus/afl-clang-lto++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/main.cpp" -o CMakeFiles/medium.dir/main.cpp.s

# Object files for target medium
medium_OBJECTS = \
"CMakeFiles/medium.dir/airplane_object.cpp.o" \
"CMakeFiles/medium.dir/main.cpp.o"

# External object files for target medium
medium_EXTERNAL_OBJECTS =

medium: CMakeFiles/medium.dir/airplane_object.cpp.o
medium: CMakeFiles/medium.dir/main.cpp.o
medium: CMakeFiles/medium.dir/build.make
medium: CMakeFiles/medium.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable medium"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/medium.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/medium.dir/build: medium

.PHONY : CMakeFiles/medium.dir/build

CMakeFiles/medium.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/medium.dir/cmake_clean.cmake
.PHONY : CMakeFiles/medium.dir/clean

CMakeFiles/medium.dir/depend:
	cd "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz" "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz" "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build" "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build" "/Users/george/Desktop/CS Capstone/capstone/medium-level-to-fuzz/build/CMakeFiles/medium.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/medium.dir/depend


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
CMAKE_SOURCE_DIR = /mnt/c/Users/barev/Desktop/RayTracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/barev/Desktop/RayTracer

# Include any dependencies generated for this target.
include CMakeFiles/vectorexample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vectorexample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vectorexample.dir/flags.make

CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o: CMakeFiles/vectorexample.dir/flags.make
CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o: examples/vecMatrixExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barev/Desktop/RayTracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o -c /mnt/c/Users/barev/Desktop/RayTracer/examples/vecMatrixExample.cpp

CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/barev/Desktop/RayTracer/examples/vecMatrixExample.cpp > CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.i

CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/barev/Desktop/RayTracer/examples/vecMatrixExample.cpp -o CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.s

# Object files for target vectorexample
vectorexample_OBJECTS = \
"CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o"

# External object files for target vectorexample
vectorexample_EXTERNAL_OBJECTS =

vectorexample: CMakeFiles/vectorexample.dir/examples/vecMatrixExample.cpp.o
vectorexample: CMakeFiles/vectorexample.dir/build.make
vectorexample: CMakeFiles/vectorexample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/barev/Desktop/RayTracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vectorexample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vectorexample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vectorexample.dir/build: vectorexample

.PHONY : CMakeFiles/vectorexample.dir/build

CMakeFiles/vectorexample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vectorexample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vectorexample.dir/clean

CMakeFiles/vectorexample.dir/depend:
	cd /mnt/c/Users/barev/Desktop/RayTracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/barev/Desktop/RayTracer /mnt/c/Users/barev/Desktop/RayTracer /mnt/c/Users/barev/Desktop/RayTracer /mnt/c/Users/barev/Desktop/RayTracer /mnt/c/Users/barev/Desktop/RayTracer/CMakeFiles/vectorexample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vectorexample.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer

# Include any dependencies generated for this target.
include source/CMakeFiles/raymovie.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/raymovie.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/raymovie.dir/flags.make

source/CMakeFiles/raymovie.dir/raymovie.cpp.o: source/CMakeFiles/raymovie.dir/flags.make
source/CMakeFiles/raymovie.dir/raymovie.cpp.o: source/raymovie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/raymovie.dir/raymovie.cpp.o"
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raymovie.dir/raymovie.cpp.o -c /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source/raymovie.cpp

source/CMakeFiles/raymovie.dir/raymovie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raymovie.dir/raymovie.cpp.i"
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source/raymovie.cpp > CMakeFiles/raymovie.dir/raymovie.cpp.i

source/CMakeFiles/raymovie.dir/raymovie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raymovie.dir/raymovie.cpp.s"
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source/raymovie.cpp -o CMakeFiles/raymovie.dir/raymovie.cpp.s

source/CMakeFiles/raymovie.dir/raymovie.cpp.o.requires:

.PHONY : source/CMakeFiles/raymovie.dir/raymovie.cpp.o.requires

source/CMakeFiles/raymovie.dir/raymovie.cpp.o.provides: source/CMakeFiles/raymovie.dir/raymovie.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/raymovie.dir/build.make source/CMakeFiles/raymovie.dir/raymovie.cpp.o.provides.build
.PHONY : source/CMakeFiles/raymovie.dir/raymovie.cpp.o.provides

source/CMakeFiles/raymovie.dir/raymovie.cpp.o.provides.build: source/CMakeFiles/raymovie.dir/raymovie.cpp.o


# Object files for target raymovie
raymovie_OBJECTS = \
"CMakeFiles/raymovie.dir/raymovie.cpp.o"

# External object files for target raymovie
raymovie_EXTERNAL_OBJECTS =

source/raymovie: source/CMakeFiles/raymovie.dir/raymovie.cpp.o
source/raymovie: source/CMakeFiles/raymovie.dir/build.make
source/raymovie: framework/libframework.a
source/raymovie: external/glfw-3.2.1/src/libglfw3.a
source/raymovie: external/glfw-3.2.1/src/libglfw3.a
source/raymovie: source/CMakeFiles/raymovie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raymovie"
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raymovie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/raymovie.dir/build: source/raymovie

.PHONY : source/CMakeFiles/raymovie.dir/build

source/CMakeFiles/raymovie.dir/requires: source/CMakeFiles/raymovie.dir/raymovie.cpp.o.requires

.PHONY : source/CMakeFiles/raymovie.dir/requires

source/CMakeFiles/raymovie.dir/clean:
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source && $(CMAKE_COMMAND) -P CMakeFiles/raymovie.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/raymovie.dir/clean

source/CMakeFiles/raymovie.dir/depend:
	cd /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/source/CMakeFiles/raymovie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/raymovie.dir/depend


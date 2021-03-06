# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.7.2_1/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/CMakeFiles /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Blueshift/Desktop/Programmiersprachen/programmiersprachen-raytracer/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named nanovg

# Build rule for target.
nanovg: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 nanovg
.PHONY : nanovg

# fast build rule for target.
nanovg/fast:
	$(MAKE) -f CMakeFiles/nanovg.dir/build.make CMakeFiles/nanovg.dir/build
.PHONY : nanovg/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) -f external/glfw-3.2.1/src/CMakeFiles/glfw.dir/build.make external/glfw-3.2.1/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

#=============================================================================
# Target rules for targets named framework

# Build rule for target.
framework: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 framework
.PHONY : framework

# fast build rule for target.
framework/fast:
	$(MAKE) -f framework/CMakeFiles/framework.dir/build.make framework/CMakeFiles/framework.dir/build
.PHONY : framework/fast

#=============================================================================
# Target rules for targets named aufgabe65

# Build rule for target.
aufgabe65: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 aufgabe65
.PHONY : aufgabe65

# fast build rule for target.
aufgabe65/fast:
	$(MAKE) -f source/CMakeFiles/aufgabe65.dir/build.make source/CMakeFiles/aufgabe65.dir/build
.PHONY : aufgabe65/fast

#=============================================================================
# Target rules for targets named raytracer

# Build rule for target.
raytracer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 raytracer
.PHONY : raytracer

# fast build rule for target.
raytracer/fast:
	$(MAKE) -f source/CMakeFiles/raytracer.dir/build.make source/CMakeFiles/raytracer.dir/build
.PHONY : raytracer/fast

#=============================================================================
# Target rules for targets named raymovie

# Build rule for target.
raymovie: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 raymovie
.PHONY : raymovie

# fast build rule for target.
raymovie/fast:
	$(MAKE) -f source/CMakeFiles/raymovie.dir/build.make source/CMakeFiles/raymovie.dir/build
.PHONY : raymovie/fast

#=============================================================================
# Target rules for targets named tests

# Build rule for target.
tests: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tests
.PHONY : tests

# fast build rule for target.
tests/fast:
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/build
.PHONY : tests/fast

#=============================================================================
# Target rules for targets named example

# Build rule for target.
example: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 example
.PHONY : example

# fast build rule for target.
example/fast:
	$(MAKE) -f source/CMakeFiles/example.dir/build.make source/CMakeFiles/example.dir/build
.PHONY : example/fast

external/nanovg/src/nanovg.o: external/nanovg/src/nanovg.c.o

.PHONY : external/nanovg/src/nanovg.o

# target to build an object file
external/nanovg/src/nanovg.c.o:
	$(MAKE) -f CMakeFiles/nanovg.dir/build.make CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.o
.PHONY : external/nanovg/src/nanovg.c.o

external/nanovg/src/nanovg.i: external/nanovg/src/nanovg.c.i

.PHONY : external/nanovg/src/nanovg.i

# target to preprocess a source file
external/nanovg/src/nanovg.c.i:
	$(MAKE) -f CMakeFiles/nanovg.dir/build.make CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.i
.PHONY : external/nanovg/src/nanovg.c.i

external/nanovg/src/nanovg.s: external/nanovg/src/nanovg.c.s

.PHONY : external/nanovg/src/nanovg.s

# target to generate assembly for a file
external/nanovg/src/nanovg.c.s:
	$(MAKE) -f CMakeFiles/nanovg.dir/build.make CMakeFiles/nanovg.dir/external/nanovg/src/nanovg.c.s
.PHONY : external/nanovg/src/nanovg.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... install/local"
	@echo "... nanovg"
	@echo "... glfw"
	@echo "... framework"
	@echo "... aufgabe65"
	@echo "... raytracer"
	@echo "... raymovie"
	@echo "... tests"
	@echo "... example"
	@echo "... external/nanovg/src/nanovg.o"
	@echo "... external/nanovg/src/nanovg.i"
	@echo "... external/nanovg/src/nanovg.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


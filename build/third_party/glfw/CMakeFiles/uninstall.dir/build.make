# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/smallboyc/Documents/imac/SI/wolf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/smallboyc/Documents/imac/SI/wolf/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include third_party/glfw/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include third_party/glfw/CMakeFiles/uninstall.dir/progress.make

third_party/glfw/CMakeFiles/uninstall:
	cd /Users/smallboyc/Documents/imac/SI/wolf/build/third_party/glfw && /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -P /Users/smallboyc/Documents/imac/SI/wolf/build/third_party/glfw/cmake_uninstall.cmake

uninstall: third_party/glfw/CMakeFiles/uninstall
uninstall: third_party/glfw/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
third_party/glfw/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : third_party/glfw/CMakeFiles/uninstall.dir/build

third_party/glfw/CMakeFiles/uninstall.dir/clean:
	cd /Users/smallboyc/Documents/imac/SI/wolf/build/third_party/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : third_party/glfw/CMakeFiles/uninstall.dir/clean

third_party/glfw/CMakeFiles/uninstall.dir/depend:
	cd /Users/smallboyc/Documents/imac/SI/wolf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/smallboyc/Documents/imac/SI/wolf /Users/smallboyc/Documents/imac/SI/wolf/third_party/glfw /Users/smallboyc/Documents/imac/SI/wolf/build /Users/smallboyc/Documents/imac/SI/wolf/build/third_party/glfw /Users/smallboyc/Documents/imac/SI/wolf/build/third_party/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : third_party/glfw/CMakeFiles/uninstall.dir/depend


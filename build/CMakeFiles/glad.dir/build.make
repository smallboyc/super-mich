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

# Include any dependencies generated for this target.
include CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glad.dir/flags.make

CMakeFiles/glad.dir/third_party/glad/src/glad.c.o: CMakeFiles/glad.dir/flags.make
CMakeFiles/glad.dir/third_party/glad/src/glad.c.o: /Users/smallboyc/Documents/imac/SI/wolf/third_party/glad/src/glad.c
CMakeFiles/glad.dir/third_party/glad/src/glad.c.o: CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/smallboyc/Documents/imac/SI/wolf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/glad.dir/third_party/glad/src/glad.c.o"
	/opt/homebrew/bin/aarch64-apple-darwin23-gcc-13 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/glad.dir/third_party/glad/src/glad.c.o -MF CMakeFiles/glad.dir/third_party/glad/src/glad.c.o.d -o CMakeFiles/glad.dir/third_party/glad/src/glad.c.o -c /Users/smallboyc/Documents/imac/SI/wolf/third_party/glad/src/glad.c

CMakeFiles/glad.dir/third_party/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/third_party/glad/src/glad.c.i"
	/opt/homebrew/bin/aarch64-apple-darwin23-gcc-13 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smallboyc/Documents/imac/SI/wolf/third_party/glad/src/glad.c > CMakeFiles/glad.dir/third_party/glad/src/glad.c.i

CMakeFiles/glad.dir/third_party/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/third_party/glad/src/glad.c.s"
	/opt/homebrew/bin/aarch64-apple-darwin23-gcc-13 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smallboyc/Documents/imac/SI/wolf/third_party/glad/src/glad.c -o CMakeFiles/glad.dir/third_party/glad/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/third_party/glad/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libglad.a: CMakeFiles/glad.dir/third_party/glad/src/glad.c.o
libglad.a: CMakeFiles/glad.dir/build.make
libglad.a: CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/smallboyc/Documents/imac/SI/wolf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	$(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glad.dir/build: libglad.a
.PHONY : CMakeFiles/glad.dir/build

CMakeFiles/glad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glad.dir/clean

CMakeFiles/glad.dir/depend:
	cd /Users/smallboyc/Documents/imac/SI/wolf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/smallboyc/Documents/imac/SI/wolf /Users/smallboyc/Documents/imac/SI/wolf /Users/smallboyc/Documents/imac/SI/wolf/build /Users/smallboyc/Documents/imac/SI/wolf/build /Users/smallboyc/Documents/imac/SI/wolf/build/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/glad.dir/depend


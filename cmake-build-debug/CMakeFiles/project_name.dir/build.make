# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rostaroghani/Documents/GitHub/97105963

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_name.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_name.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_name.dir/flags.make

CMakeFiles/project_name.dir/src/logic.c.o: CMakeFiles/project_name.dir/flags.make
CMakeFiles/project_name.dir/src/logic.c.o: ../src/logic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project_name.dir/src/logic.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_name.dir/src/logic.c.o   -c /Users/rostaroghani/Documents/GitHub/97105963/src/logic.c

CMakeFiles/project_name.dir/src/logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_name.dir/src/logic.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rostaroghani/Documents/GitHub/97105963/src/logic.c > CMakeFiles/project_name.dir/src/logic.c.i

CMakeFiles/project_name.dir/src/logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_name.dir/src/logic.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rostaroghani/Documents/GitHub/97105963/src/logic.c -o CMakeFiles/project_name.dir/src/logic.c.s

CMakeFiles/project_name.dir/src/physics.c.o: CMakeFiles/project_name.dir/flags.make
CMakeFiles/project_name.dir/src/physics.c.o: ../src/physics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project_name.dir/src/physics.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_name.dir/src/physics.c.o   -c /Users/rostaroghani/Documents/GitHub/97105963/src/physics.c

CMakeFiles/project_name.dir/src/physics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_name.dir/src/physics.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rostaroghani/Documents/GitHub/97105963/src/physics.c > CMakeFiles/project_name.dir/src/physics.c.i

CMakeFiles/project_name.dir/src/physics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_name.dir/src/physics.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rostaroghani/Documents/GitHub/97105963/src/physics.c -o CMakeFiles/project_name.dir/src/physics.c.s

CMakeFiles/project_name.dir/src/simple_snake.c.o: CMakeFiles/project_name.dir/flags.make
CMakeFiles/project_name.dir/src/simple_snake.c.o: ../src/simple_snake.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project_name.dir/src/simple_snake.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_name.dir/src/simple_snake.c.o   -c /Users/rostaroghani/Documents/GitHub/97105963/src/simple_snake.c

CMakeFiles/project_name.dir/src/simple_snake.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_name.dir/src/simple_snake.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rostaroghani/Documents/GitHub/97105963/src/simple_snake.c > CMakeFiles/project_name.dir/src/simple_snake.c.i

CMakeFiles/project_name.dir/src/simple_snake.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_name.dir/src/simple_snake.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rostaroghani/Documents/GitHub/97105963/src/simple_snake.c -o CMakeFiles/project_name.dir/src/simple_snake.c.s

CMakeFiles/project_name.dir/src/view.c.o: CMakeFiles/project_name.dir/flags.make
CMakeFiles/project_name.dir/src/view.c.o: ../src/view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/project_name.dir/src/view.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_name.dir/src/view.c.o   -c /Users/rostaroghani/Documents/GitHub/97105963/src/view.c

CMakeFiles/project_name.dir/src/view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_name.dir/src/view.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rostaroghani/Documents/GitHub/97105963/src/view.c > CMakeFiles/project_name.dir/src/view.c.i

CMakeFiles/project_name.dir/src/view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_name.dir/src/view.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rostaroghani/Documents/GitHub/97105963/src/view.c -o CMakeFiles/project_name.dir/src/view.c.s

# Object files for target project_name
project_name_OBJECTS = \
"CMakeFiles/project_name.dir/src/logic.c.o" \
"CMakeFiles/project_name.dir/src/physics.c.o" \
"CMakeFiles/project_name.dir/src/simple_snake.c.o" \
"CMakeFiles/project_name.dir/src/view.c.o"

# External object files for target project_name
project_name_EXTERNAL_OBJECTS =

project_name: CMakeFiles/project_name.dir/src/logic.c.o
project_name: CMakeFiles/project_name.dir/src/physics.c.o
project_name: CMakeFiles/project_name.dir/src/simple_snake.c.o
project_name: CMakeFiles/project_name.dir/src/view.c.o
project_name: CMakeFiles/project_name.dir/build.make
project_name: CMakeFiles/project_name.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable project_name"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_name.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_name.dir/build: project_name

.PHONY : CMakeFiles/project_name.dir/build

CMakeFiles/project_name.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_name.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_name.dir/clean

CMakeFiles/project_name.dir/depend:
	cd /Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rostaroghani/Documents/GitHub/97105963 /Users/rostaroghani/Documents/GitHub/97105963 /Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug /Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug /Users/rostaroghani/Documents/GitHub/97105963/cmake-build-debug/CMakeFiles/project_name.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_name.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programms\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programms\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 3a\13"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/13.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/13.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/13.dir/flags.make

CMakeFiles/13.dir/main.c.obj: CMakeFiles/13.dir/flags.make
CMakeFiles/13.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/13.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\13.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 3a\13\main.c"

CMakeFiles/13.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/13.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 3a\13\main.c" > CMakeFiles\13.dir\main.c.i

CMakeFiles/13.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/13.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 3a\13\main.c" -o CMakeFiles\13.dir\main.c.s

# Object files for target 13
13_OBJECTS = \
"CMakeFiles/13.dir/main.c.obj"

# External object files for target 13
13_EXTERNAL_OBJECTS =

13.exe: CMakeFiles/13.dir/main.c.obj
13.exe: CMakeFiles/13.dir/build.make
13.exe: CMakeFiles/13.dir/linklibs.rsp
13.exe: CMakeFiles/13.dir/objects1.rsp
13.exe: CMakeFiles/13.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 13.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\13.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/13.dir/build: 13.exe
.PHONY : CMakeFiles/13.dir/build

CMakeFiles/13.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\13.dir\cmake_clean.cmake
.PHONY : CMakeFiles/13.dir/clean

CMakeFiles/13.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 3a\13" "D:\BGTU\Programming Basics\Lab 3a\13" "D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 3a\13\cmake-build-debug\CMakeFiles\13.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/13.dir/depend


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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 2b\football match"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/football_match.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/football_match.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/football_match.dir/flags.make

CMakeFiles/football_match.dir/main.c.obj: CMakeFiles/football_match.dir/flags.make
CMakeFiles/football_match.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/football_match.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\football_match.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 2b\football match\main.c"

CMakeFiles/football_match.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/football_match.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 2b\football match\main.c" > CMakeFiles\football_match.dir\main.c.i

CMakeFiles/football_match.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/football_match.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 2b\football match\main.c" -o CMakeFiles\football_match.dir\main.c.s

# Object files for target football_match
football_match_OBJECTS = \
"CMakeFiles/football_match.dir/main.c.obj"

# External object files for target football_match
football_match_EXTERNAL_OBJECTS =

football_match.exe: CMakeFiles/football_match.dir/main.c.obj
football_match.exe: CMakeFiles/football_match.dir/build.make
football_match.exe: CMakeFiles/football_match.dir/linklibs.rsp
football_match.exe: CMakeFiles/football_match.dir/objects1.rsp
football_match.exe: CMakeFiles/football_match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable football_match.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\football_match.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/football_match.dir/build: football_match.exe
.PHONY : CMakeFiles/football_match.dir/build

CMakeFiles/football_match.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\football_match.dir\cmake_clean.cmake
.PHONY : CMakeFiles/football_match.dir/clean

CMakeFiles/football_match.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 2b\football match" "D:\BGTU\Programming Basics\Lab 2b\football match" "D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 2b\football match\cmake-build-debug\CMakeFiles\football_match.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/football_match.dir/depend


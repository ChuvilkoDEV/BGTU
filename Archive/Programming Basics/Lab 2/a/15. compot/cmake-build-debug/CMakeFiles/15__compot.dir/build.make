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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 2a\15. compot"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/15__compot.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/15__compot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/15__compot.dir/flags.make

CMakeFiles/15__compot.dir/main.c.obj: CMakeFiles/15__compot.dir/flags.make
CMakeFiles/15__compot.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/15__compot.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\15__compot.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 2a\15. compot\main.c"

CMakeFiles/15__compot.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/15__compot.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 2a\15. compot\main.c" > CMakeFiles\15__compot.dir\main.c.i

CMakeFiles/15__compot.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/15__compot.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 2a\15. compot\main.c" -o CMakeFiles\15__compot.dir\main.c.s

# Object files for target 15__compot
15__compot_OBJECTS = \
"CMakeFiles/15__compot.dir/main.c.obj"

# External object files for target 15__compot
15__compot_EXTERNAL_OBJECTS =

15__compot.exe: CMakeFiles/15__compot.dir/main.c.obj
15__compot.exe: CMakeFiles/15__compot.dir/build.make
15__compot.exe: CMakeFiles/15__compot.dir/linklibs.rsp
15__compot.exe: CMakeFiles/15__compot.dir/objects1.rsp
15__compot.exe: CMakeFiles/15__compot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 15__compot.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\15__compot.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/15__compot.dir/build: 15__compot.exe
.PHONY : CMakeFiles/15__compot.dir/build

CMakeFiles/15__compot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\15__compot.dir\cmake_clean.cmake
.PHONY : CMakeFiles/15__compot.dir/clean

CMakeFiles/15__compot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 2a\15. compot" "D:\BGTU\Programming Basics\Lab 2a\15. compot" "D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 2a\15. compot\cmake-build-debug\CMakeFiles\15__compot.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/15__compot.dir/depend

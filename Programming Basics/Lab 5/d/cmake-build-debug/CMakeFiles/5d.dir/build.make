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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\lab 5d"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\lab 5d\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/5d.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/5d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5d.dir/flags.make

CMakeFiles/5d.dir/main.c.obj: CMakeFiles/5d.dir/flags.make
CMakeFiles/5d.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\lab 5d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5d.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5d.dir\main.c.obj -c "D:\BGTU\Programming Basics\lab 5d\main.c"

CMakeFiles/5d.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5d.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\lab 5d\main.c" > CMakeFiles\5d.dir\main.c.i

CMakeFiles/5d.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5d.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\lab 5d\main.c" -o CMakeFiles\5d.dir\main.c.s

CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.obj: CMakeFiles/5d.dir/flags.make
CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.obj: ../libs/data_structures/matrix/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\lab 5d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5d.dir\libs\data_structures\matrix\matrix.c.obj -c "D:\BGTU\Programming Basics\lab 5d\libs\data_structures\matrix\matrix.c"

CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\lab 5d\libs\data_structures\matrix\matrix.c" > CMakeFiles\5d.dir\libs\data_structures\matrix\matrix.c.i

CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\lab 5d\libs\data_structures\matrix\matrix.c" -o CMakeFiles\5d.dir\libs\data_structures\matrix\matrix.c.s

CMakeFiles/5d.dir/libs/algorithms/algorithms.c.obj: CMakeFiles/5d.dir/flags.make
CMakeFiles/5d.dir/libs/algorithms/algorithms.c.obj: ../libs/algorithms/algorithms.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\lab 5d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/5d.dir/libs/algorithms/algorithms.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\5d.dir\libs\algorithms\algorithms.c.obj -c "D:\BGTU\Programming Basics\lab 5d\libs\algorithms\algorithms.c"

CMakeFiles/5d.dir/libs/algorithms/algorithms.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5d.dir/libs/algorithms/algorithms.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\lab 5d\libs\algorithms\algorithms.c" > CMakeFiles\5d.dir\libs\algorithms\algorithms.c.i

CMakeFiles/5d.dir/libs/algorithms/algorithms.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5d.dir/libs/algorithms/algorithms.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\lab 5d\libs\algorithms\algorithms.c" -o CMakeFiles\5d.dir\libs\algorithms\algorithms.c.s

# Object files for target 5d
5d_OBJECTS = \
"CMakeFiles/5d.dir/main.c.obj" \
"CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.obj" \
"CMakeFiles/5d.dir/libs/algorithms/algorithms.c.obj"

# External object files for target 5d
5d_EXTERNAL_OBJECTS =

5d.exe: CMakeFiles/5d.dir/main.c.obj
5d.exe: CMakeFiles/5d.dir/libs/data_structures/matrix/matrix.c.obj
5d.exe: CMakeFiles/5d.dir/libs/algorithms/algorithms.c.obj
5d.exe: CMakeFiles/5d.dir/build.make
5d.exe: CMakeFiles/5d.dir/linklibs.rsp
5d.exe: CMakeFiles/5d.dir/objects1.rsp
5d.exe: CMakeFiles/5d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\lab 5d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable 5d.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5d.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5d.dir/build: 5d.exe
.PHONY : CMakeFiles/5d.dir/build

CMakeFiles/5d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5d.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5d.dir/clean

CMakeFiles/5d.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\lab 5d" "D:\BGTU\Programming Basics\lab 5d" "D:\BGTU\Programming Basics\lab 5d\cmake-build-debug" "D:\BGTU\Programming Basics\lab 5d\cmake-build-debug" "D:\BGTU\Programming Basics\lab 5d\cmake-build-debug\CMakeFiles\5d.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/5d.dir/depend


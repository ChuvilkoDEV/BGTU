# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\BGTU\Архив\ASD\Lab 7\Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Code.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Code.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Code.dir/flags.make

CMakeFiles/Code.dir/main.c.obj: CMakeFiles/Code.dir/flags.make
CMakeFiles/Code.dir/main.c.obj: D:/BGTU/Архив/ASD/Lab\ 7/Code/main.c
CMakeFiles/Code.dir/main.c.obj: CMakeFiles/Code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Code.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Code.dir/main.c.obj -MF CMakeFiles\Code.dir\main.c.obj.d -o CMakeFiles\Code.dir\main.c.obj -c "D:\BGTU\Архив\ASD\Lab 7\Code\main.c"

CMakeFiles/Code.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Code.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Архив\ASD\Lab 7\Code\main.c" > CMakeFiles\Code.dir\main.c.i

CMakeFiles/Code.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Code.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Архив\ASD\Lab 7\Code\main.c" -o CMakeFiles\Code.dir\main.c.s

CMakeFiles/Code.dir/Tree/Tree.c.obj: CMakeFiles/Code.dir/flags.make
CMakeFiles/Code.dir/Tree/Tree.c.obj: D:/BGTU/Архив/ASD/Lab\ 7/Code/Tree/Tree.c
CMakeFiles/Code.dir/Tree/Tree.c.obj: CMakeFiles/Code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Code.dir/Tree/Tree.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Code.dir/Tree/Tree.c.obj -MF CMakeFiles\Code.dir\Tree\Tree.c.obj.d -o CMakeFiles\Code.dir\Tree\Tree.c.obj -c "D:\BGTU\Архив\ASD\Lab 7\Code\Tree\Tree.c"

CMakeFiles/Code.dir/Tree/Tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Code.dir/Tree/Tree.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Архив\ASD\Lab 7\Code\Tree\Tree.c" > CMakeFiles\Code.dir\Tree\Tree.c.i

CMakeFiles/Code.dir/Tree/Tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Code.dir/Tree/Tree.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Архив\ASD\Lab 7\Code\Tree\Tree.c" -o CMakeFiles\Code.dir\Tree\Tree.c.s

# Object files for target Code
Code_OBJECTS = \
"CMakeFiles/Code.dir/main.c.obj" \
"CMakeFiles/Code.dir/Tree/Tree.c.obj"

# External object files for target Code
Code_EXTERNAL_OBJECTS =

Code.exe: CMakeFiles/Code.dir/main.c.obj
Code.exe: CMakeFiles/Code.dir/Tree/Tree.c.obj
Code.exe: CMakeFiles/Code.dir/build.make
Code.exe: CMakeFiles/Code.dir/linkLibs.rsp
Code.exe: CMakeFiles/Code.dir/objects1
Code.exe: CMakeFiles/Code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Code.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Code.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Code.dir/build: Code.exe
.PHONY : CMakeFiles/Code.dir/build

CMakeFiles/Code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Code.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Code.dir/clean

CMakeFiles/Code.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Архив\ASD\Lab 7\Code" "D:\BGTU\Архив\ASD\Lab 7\Code" "D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug" "D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug" "D:\BGTU\Архив\ASD\Lab 7\Code\cmake-build-debug\CMakeFiles\Code.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Code.dir/depend


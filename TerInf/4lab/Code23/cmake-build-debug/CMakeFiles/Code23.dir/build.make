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
CMAKE_SOURCE_DIR = D:\BGTU\TerInf\4lab\Code23

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\BGTU\TerInf\4lab\Code23\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Code23.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Code23.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Code23.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Code23.dir/flags.make

CMakeFiles/Code23.dir/main.cpp.obj: CMakeFiles/Code23.dir/flags.make
CMakeFiles/Code23.dir/main.cpp.obj: D:/BGTU/TerInf/4lab/Code23/main.cpp
CMakeFiles/Code23.dir/main.cpp.obj: CMakeFiles/Code23.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\BGTU\TerInf\4lab\Code23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Code23.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Code23.dir/main.cpp.obj -MF CMakeFiles\Code23.dir\main.cpp.obj.d -o CMakeFiles\Code23.dir\main.cpp.obj -c D:\BGTU\TerInf\4lab\Code23\main.cpp

CMakeFiles/Code23.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code23.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\BGTU\TerInf\4lab\Code23\main.cpp > CMakeFiles\Code23.dir\main.cpp.i

CMakeFiles/Code23.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code23.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\BGTU\TerInf\4lab\Code23\main.cpp -o CMakeFiles\Code23.dir\main.cpp.s

# Object files for target Code23
Code23_OBJECTS = \
"CMakeFiles/Code23.dir/main.cpp.obj"

# External object files for target Code23
Code23_EXTERNAL_OBJECTS =

Code23.exe: CMakeFiles/Code23.dir/main.cpp.obj
Code23.exe: CMakeFiles/Code23.dir/build.make
Code23.exe: CMakeFiles/Code23.dir/linkLibs.rsp
Code23.exe: CMakeFiles/Code23.dir/objects1
Code23.exe: CMakeFiles/Code23.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\BGTU\TerInf\4lab\Code23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Code23.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Code23.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Code23.dir/build: Code23.exe
.PHONY : CMakeFiles/Code23.dir/build

CMakeFiles/Code23.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Code23.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Code23.dir/clean

CMakeFiles/Code23.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\BGTU\TerInf\4lab\Code23 D:\BGTU\TerInf\4lab\Code23 D:\BGTU\TerInf\4lab\Code23\cmake-build-debug D:\BGTU\TerInf\4lab\Code23\cmake-build-debug D:\BGTU\TerInf\4lab\Code23\cmake-build-debug\CMakeFiles\Code23.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Code23.dir/depend


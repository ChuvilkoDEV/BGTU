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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\6c\12. Stupid CAt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/12__Stupid_CAt.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/12__Stupid_CAt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12__Stupid_CAt.dir/flags.make

CMakeFiles/12__Stupid_CAt.dir/main.cpp.obj: CMakeFiles/12__Stupid_CAt.dir/flags.make
CMakeFiles/12__Stupid_CAt.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/12__Stupid_CAt.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\12__Stupid_CAt.dir\main.cpp.obj -c "D:\BGTU\Programming Basics\6c\12. Stupid CAt\main.cpp"

CMakeFiles/12__Stupid_CAt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/12__Stupid_CAt.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\BGTU\Programming Basics\6c\12. Stupid CAt\main.cpp" > CMakeFiles\12__Stupid_CAt.dir\main.cpp.i

CMakeFiles/12__Stupid_CAt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/12__Stupid_CAt.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\BGTU\Programming Basics\6c\12. Stupid CAt\main.cpp" -o CMakeFiles\12__Stupid_CAt.dir\main.cpp.s

# Object files for target 12__Stupid_CAt
12__Stupid_CAt_OBJECTS = \
"CMakeFiles/12__Stupid_CAt.dir/main.cpp.obj"

# External object files for target 12__Stupid_CAt
12__Stupid_CAt_EXTERNAL_OBJECTS =

12__Stupid_CAt.exe: CMakeFiles/12__Stupid_CAt.dir/main.cpp.obj
12__Stupid_CAt.exe: CMakeFiles/12__Stupid_CAt.dir/build.make
12__Stupid_CAt.exe: CMakeFiles/12__Stupid_CAt.dir/linklibs.rsp
12__Stupid_CAt.exe: CMakeFiles/12__Stupid_CAt.dir/objects1.rsp
12__Stupid_CAt.exe: CMakeFiles/12__Stupid_CAt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 12__Stupid_CAt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12__Stupid_CAt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12__Stupid_CAt.dir/build: 12__Stupid_CAt.exe
.PHONY : CMakeFiles/12__Stupid_CAt.dir/build

CMakeFiles/12__Stupid_CAt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\12__Stupid_CAt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/12__Stupid_CAt.dir/clean

CMakeFiles/12__Stupid_CAt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\6c\12. Stupid CAt" "D:\BGTU\Programming Basics\6c\12. Stupid CAt" "D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug" "D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug" "D:\BGTU\Programming Basics\6c\12. Stupid CAt\cmake-build-debug\CMakeFiles\12__Stupid_CAt.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/12__Stupid_CAt.dir/depend

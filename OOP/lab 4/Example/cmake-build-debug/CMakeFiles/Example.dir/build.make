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
CMAKE_SOURCE_DIR = "D:\BGTU\OOP\lab 4\Example"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\OOP\lab 4\Example\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Example.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Example.dir/flags.make

CMakeFiles/Example.dir/main.cpp.obj: CMakeFiles/Example.dir/flags.make
CMakeFiles/Example.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\OOP\lab 4\Example\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Example.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Example.dir\main.cpp.obj -c "D:\BGTU\OOP\lab 4\Example\main.cpp"

CMakeFiles/Example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Example.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\BGTU\OOP\lab 4\Example\main.cpp" > CMakeFiles\Example.dir\main.cpp.i

CMakeFiles/Example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Example.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\BGTU\OOP\lab 4\Example\main.cpp" -o CMakeFiles\Example.dir\main.cpp.s

# Object files for target Example
Example_OBJECTS = \
"CMakeFiles/Example.dir/main.cpp.obj"

# External object files for target Example
Example_EXTERNAL_OBJECTS =

Example.exe: CMakeFiles/Example.dir/main.cpp.obj
Example.exe: CMakeFiles/Example.dir/build.make
Example.exe: CMakeFiles/Example.dir/linklibs.rsp
Example.exe: CMakeFiles/Example.dir/objects1.rsp
Example.exe: CMakeFiles/Example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\OOP\lab 4\Example\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Example.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Example.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Example.dir/build: Example.exe
.PHONY : CMakeFiles/Example.dir/build

CMakeFiles/Example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Example.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Example.dir/clean

CMakeFiles/Example.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\OOP\lab 4\Example" "D:\BGTU\OOP\lab 4\Example" "D:\BGTU\OOP\lab 4\Example\cmake-build-debug" "D:\BGTU\OOP\lab 4\Example\cmake-build-debug" "D:\BGTU\OOP\lab 4\Example\cmake-build-debug\CMakeFiles\Example.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Example.dir/depend


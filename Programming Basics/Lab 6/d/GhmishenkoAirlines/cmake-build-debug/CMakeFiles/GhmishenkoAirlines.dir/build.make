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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/GhmishenkoAirlines.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/GhmishenkoAirlines.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GhmishenkoAirlines.dir/flags.make

CMakeFiles/GhmishenkoAirlines.dir/main.cpp.obj: CMakeFiles/GhmishenkoAirlines.dir/flags.make
CMakeFiles/GhmishenkoAirlines.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GhmishenkoAirlines.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GhmishenkoAirlines.dir\main.cpp.obj -c "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\main.cpp"

CMakeFiles/GhmishenkoAirlines.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GhmishenkoAirlines.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\main.cpp" > CMakeFiles\GhmishenkoAirlines.dir\main.cpp.i

CMakeFiles/GhmishenkoAirlines.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GhmishenkoAirlines.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\main.cpp" -o CMakeFiles\GhmishenkoAirlines.dir\main.cpp.s

# Object files for target GhmishenkoAirlines
GhmishenkoAirlines_OBJECTS = \
"CMakeFiles/GhmishenkoAirlines.dir/main.cpp.obj"

# External object files for target GhmishenkoAirlines
GhmishenkoAirlines_EXTERNAL_OBJECTS =

GhmishenkoAirlines.exe: CMakeFiles/GhmishenkoAirlines.dir/main.cpp.obj
GhmishenkoAirlines.exe: CMakeFiles/GhmishenkoAirlines.dir/build.make
GhmishenkoAirlines.exe: CMakeFiles/GhmishenkoAirlines.dir/linklibs.rsp
GhmishenkoAirlines.exe: CMakeFiles/GhmishenkoAirlines.dir/objects1.rsp
GhmishenkoAirlines.exe: CMakeFiles/GhmishenkoAirlines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GhmishenkoAirlines.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GhmishenkoAirlines.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GhmishenkoAirlines.dir/build: GhmishenkoAirlines.exe
.PHONY : CMakeFiles/GhmishenkoAirlines.dir/build

CMakeFiles/GhmishenkoAirlines.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GhmishenkoAirlines.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GhmishenkoAirlines.dir/clean

CMakeFiles/GhmishenkoAirlines.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines" "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines" "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug" "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug" "D:\BGTU\Programming Basics\6d\GhmishenkoAirlines\cmake-build-debug\CMakeFiles\GhmishenkoAirlines.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GhmishenkoAirlines.dir/depend


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
CMAKE_SOURCE_DIR = "D:\BGTU\Programming Basics\Lab 5a\main"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bitSet.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/bitSet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitSet.dir/flags.make

CMakeFiles/bitSet.dir/main.c.obj: CMakeFiles/bitSet.dir/flags.make
CMakeFiles/bitSet.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bitSet.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bitSet.dir\main.c.obj -c "D:\BGTU\Programming Basics\Lab 5a\main\main.c"

CMakeFiles/bitSet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitSet.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 5a\main\main.c" > CMakeFiles\bitSet.dir\main.c.i

CMakeFiles/bitSet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitSet.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 5a\main\main.c" -o CMakeFiles\bitSet.dir\main.c.s

CMakeFiles/bitSet.dir/bitSet.c.obj: CMakeFiles/bitSet.dir/flags.make
CMakeFiles/bitSet.dir/bitSet.c.obj: ../bitSet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bitSet.dir/bitSet.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bitSet.dir\bitSet.c.obj -c "D:\BGTU\Programming Basics\Lab 5a\main\bitSet.c"

CMakeFiles/bitSet.dir/bitSet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitSet.dir/bitSet.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 5a\main\bitSet.c" > CMakeFiles\bitSet.dir\bitSet.c.i

CMakeFiles/bitSet.dir/bitSet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitSet.dir/bitSet.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 5a\main\bitSet.c" -o CMakeFiles\bitSet.dir\bitSet.c.s

CMakeFiles/bitSet.dir/unorderedset.c.obj: CMakeFiles/bitSet.dir/flags.make
CMakeFiles/bitSet.dir/unorderedset.c.obj: ../unorderedset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bitSet.dir/unorderedset.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bitSet.dir\unorderedset.c.obj -c "D:\BGTU\Programming Basics\Lab 5a\main\unorderedset.c"

CMakeFiles/bitSet.dir/unorderedset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitSet.dir/unorderedset.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 5a\main\unorderedset.c" > CMakeFiles\bitSet.dir\unorderedset.c.i

CMakeFiles/bitSet.dir/unorderedset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitSet.dir/unorderedset.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 5a\main\unorderedset.c" -o CMakeFiles\bitSet.dir\unorderedset.c.s

CMakeFiles/bitSet.dir/orderedarrayset.c.obj: CMakeFiles/bitSet.dir/flags.make
CMakeFiles/bitSet.dir/orderedarrayset.c.obj: ../orderedarrayset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/bitSet.dir/orderedarrayset.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bitSet.dir\orderedarrayset.c.obj -c "D:\BGTU\Programming Basics\Lab 5a\main\orderedarrayset.c"

CMakeFiles/bitSet.dir/orderedarrayset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitSet.dir/orderedarrayset.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 5a\main\orderedarrayset.c" > CMakeFiles\bitSet.dir\orderedarrayset.c.i

CMakeFiles/bitSet.dir/orderedarrayset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitSet.dir/orderedarrayset.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 5a\main\orderedarrayset.c" -o CMakeFiles\bitSet.dir\orderedarrayset.c.s

CMakeFiles/bitSet.dir/array.c.obj: CMakeFiles/bitSet.dir/flags.make
CMakeFiles/bitSet.dir/array.c.obj: ../array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/bitSet.dir/array.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bitSet.dir\array.c.obj -c "D:\BGTU\Programming Basics\Lab 5a\main\array.c"

CMakeFiles/bitSet.dir/array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitSet.dir/array.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\BGTU\Programming Basics\Lab 5a\main\array.c" > CMakeFiles\bitSet.dir\array.c.i

CMakeFiles/bitSet.dir/array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitSet.dir/array.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-R\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\BGTU\Programming Basics\Lab 5a\main\array.c" -o CMakeFiles\bitSet.dir\array.c.s

# Object files for target bitSet
bitSet_OBJECTS = \
"CMakeFiles/bitSet.dir/main.c.obj" \
"CMakeFiles/bitSet.dir/bitSet.c.obj" \
"CMakeFiles/bitSet.dir/unorderedset.c.obj" \
"CMakeFiles/bitSet.dir/orderedarrayset.c.obj" \
"CMakeFiles/bitSet.dir/array.c.obj"

# External object files for target bitSet
bitSet_EXTERNAL_OBJECTS =

bitSet.exe: CMakeFiles/bitSet.dir/main.c.obj
bitSet.exe: CMakeFiles/bitSet.dir/bitSet.c.obj
bitSet.exe: CMakeFiles/bitSet.dir/unorderedset.c.obj
bitSet.exe: CMakeFiles/bitSet.dir/orderedarrayset.c.obj
bitSet.exe: CMakeFiles/bitSet.dir/array.c.obj
bitSet.exe: CMakeFiles/bitSet.dir/build.make
bitSet.exe: CMakeFiles/bitSet.dir/linklibs.rsp
bitSet.exe: CMakeFiles/bitSet.dir/objects1.rsp
bitSet.exe: CMakeFiles/bitSet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable bitSet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bitSet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitSet.dir/build: bitSet.exe
.PHONY : CMakeFiles/bitSet.dir/build

CMakeFiles/bitSet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bitSet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bitSet.dir/clean

CMakeFiles/bitSet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\BGTU\Programming Basics\Lab 5a\main" "D:\BGTU\Programming Basics\Lab 5a\main" "D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug" "D:\BGTU\Programming Basics\Lab 5a\main\cmake-build-debug\CMakeFiles\bitSet.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bitSet.dir/depend

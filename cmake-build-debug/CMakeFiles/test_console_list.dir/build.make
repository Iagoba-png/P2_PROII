# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2025.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2025.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\EQUIPO\CLionProjects\P2_PROII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_console_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_console_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_console_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_console_list.dir/flags.make

CMakeFiles/test_console_list.dir/codegen:
.PHONY : CMakeFiles/test_console_list.dir/codegen

CMakeFiles/test_console_list.dir/test_console_list.c.obj: CMakeFiles/test_console_list.dir/flags.make
CMakeFiles/test_console_list.dir/test_console_list.c.obj: C:/Users/EQUIPO/CLionProjects/P2_PROII/test_console_list.c
CMakeFiles/test_console_list.dir/test_console_list.c.obj: CMakeFiles/test_console_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_console_list.dir/test_console_list.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_console_list.dir/test_console_list.c.obj -MF CMakeFiles\test_console_list.dir\test_console_list.c.obj.d -o CMakeFiles\test_console_list.dir\test_console_list.c.obj -c C:\Users\EQUIPO\CLionProjects\P2_PROII\test_console_list.c

CMakeFiles/test_console_list.dir/test_console_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_console_list.dir/test_console_list.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\EQUIPO\CLionProjects\P2_PROII\test_console_list.c > CMakeFiles\test_console_list.dir\test_console_list.c.i

CMakeFiles/test_console_list.dir/test_console_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_console_list.dir/test_console_list.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\EQUIPO\CLionProjects\P2_PROII\test_console_list.c -o CMakeFiles\test_console_list.dir\test_console_list.c.s

CMakeFiles/test_console_list.dir/console_list.c.obj: CMakeFiles/test_console_list.dir/flags.make
CMakeFiles/test_console_list.dir/console_list.c.obj: C:/Users/EQUIPO/CLionProjects/P2_PROII/console_list.c
CMakeFiles/test_console_list.dir/console_list.c.obj: CMakeFiles/test_console_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_console_list.dir/console_list.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_console_list.dir/console_list.c.obj -MF CMakeFiles\test_console_list.dir\console_list.c.obj.d -o CMakeFiles\test_console_list.dir\console_list.c.obj -c C:\Users\EQUIPO\CLionProjects\P2_PROII\console_list.c

CMakeFiles/test_console_list.dir/console_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_console_list.dir/console_list.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\EQUIPO\CLionProjects\P2_PROII\console_list.c > CMakeFiles\test_console_list.dir\console_list.c.i

CMakeFiles/test_console_list.dir/console_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_console_list.dir/console_list.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\EQUIPO\CLionProjects\P2_PROII\console_list.c -o CMakeFiles\test_console_list.dir\console_list.c.s

# Object files for target test_console_list
test_console_list_OBJECTS = \
"CMakeFiles/test_console_list.dir/test_console_list.c.obj" \
"CMakeFiles/test_console_list.dir/console_list.c.obj"

# External object files for target test_console_list
test_console_list_EXTERNAL_OBJECTS =

C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/test_console_list.c.obj
C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/console_list.c.obj
C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/build.make
C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/linkLibs.rsp
C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/objects1.rsp
C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe: CMakeFiles/test_console_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable C:\Users\EQUIPO\CLionProjects\P2_PROII\bin\test_console_list.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_console_list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_console_list.dir/build: C:/Users/EQUIPO/CLionProjects/P2_PROII/bin/test_console_list.exe
.PHONY : CMakeFiles/test_console_list.dir/build

CMakeFiles/test_console_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_console_list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_console_list.dir/clean

CMakeFiles/test_console_list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\EQUIPO\CLionProjects\P2_PROII C:\Users\EQUIPO\CLionProjects\P2_PROII C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug C:\Users\EQUIPO\CLionProjects\P2_PROII\cmake-build-debug\CMakeFiles\test_console_list.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_console_list.dir/depend


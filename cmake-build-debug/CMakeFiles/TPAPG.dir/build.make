# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Raphael\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4548.31\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Raphael\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4548.31\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Raphael\Programing\Git\TPAPG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Raphael\Programing\Git\TPAPG\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TPAPG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TPAPG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TPAPG.dir/flags.make

CMakeFiles/TPAPG.dir/main.cpp.obj: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Raphael\Programing\Git\TPAPG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TPAPG.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TPAPG.dir\main.cpp.obj -c D:\Raphael\Programing\Git\TPAPG\main.cpp

CMakeFiles/TPAPG.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Raphael\Programing\Git\TPAPG\main.cpp > CMakeFiles\TPAPG.dir\main.cpp.i

CMakeFiles/TPAPG.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Raphael\Programing\Git\TPAPG\main.cpp -o CMakeFiles\TPAPG.dir\main.cpp.s

CMakeFiles/TPAPG.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/TPAPG.dir/main.cpp.obj.requires

CMakeFiles/TPAPG.dir/main.cpp.obj.provides: CMakeFiles/TPAPG.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TPAPG.dir\build.make CMakeFiles/TPAPG.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/TPAPG.dir/main.cpp.obj.provides

CMakeFiles/TPAPG.dir/main.cpp.obj.provides.build: CMakeFiles/TPAPG.dir/main.cpp.obj


CMakeFiles/TPAPG.dir/service.cpp.obj: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/service.cpp.obj: ../service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Raphael\Programing\Git\TPAPG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TPAPG.dir/service.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TPAPG.dir\service.cpp.obj -c D:\Raphael\Programing\Git\TPAPG\service.cpp

CMakeFiles/TPAPG.dir/service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/service.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Raphael\Programing\Git\TPAPG\service.cpp > CMakeFiles\TPAPG.dir\service.cpp.i

CMakeFiles/TPAPG.dir/service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/service.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Raphael\Programing\Git\TPAPG\service.cpp -o CMakeFiles\TPAPG.dir\service.cpp.s

CMakeFiles/TPAPG.dir/service.cpp.obj.requires:

.PHONY : CMakeFiles/TPAPG.dir/service.cpp.obj.requires

CMakeFiles/TPAPG.dir/service.cpp.obj.provides: CMakeFiles/TPAPG.dir/service.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TPAPG.dir\build.make CMakeFiles/TPAPG.dir/service.cpp.obj.provides.build
.PHONY : CMakeFiles/TPAPG.dir/service.cpp.obj.provides

CMakeFiles/TPAPG.dir/service.cpp.obj.provides.build: CMakeFiles/TPAPG.dir/service.cpp.obj


CMakeFiles/TPAPG.dir/supplier.cpp.obj: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/supplier.cpp.obj: ../supplier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Raphael\Programing\Git\TPAPG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TPAPG.dir/supplier.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TPAPG.dir\supplier.cpp.obj -c D:\Raphael\Programing\Git\TPAPG\supplier.cpp

CMakeFiles/TPAPG.dir/supplier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/supplier.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Raphael\Programing\Git\TPAPG\supplier.cpp > CMakeFiles\TPAPG.dir\supplier.cpp.i

CMakeFiles/TPAPG.dir/supplier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/supplier.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Raphael\Programing\Git\TPAPG\supplier.cpp -o CMakeFiles\TPAPG.dir\supplier.cpp.s

CMakeFiles/TPAPG.dir/supplier.cpp.obj.requires:

.PHONY : CMakeFiles/TPAPG.dir/supplier.cpp.obj.requires

CMakeFiles/TPAPG.dir/supplier.cpp.obj.provides: CMakeFiles/TPAPG.dir/supplier.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TPAPG.dir\build.make CMakeFiles/TPAPG.dir/supplier.cpp.obj.provides.build
.PHONY : CMakeFiles/TPAPG.dir/supplier.cpp.obj.provides

CMakeFiles/TPAPG.dir/supplier.cpp.obj.provides.build: CMakeFiles/TPAPG.dir/supplier.cpp.obj


# Object files for target TPAPG
TPAPG_OBJECTS = \
"CMakeFiles/TPAPG.dir/main.cpp.obj" \
"CMakeFiles/TPAPG.dir/service.cpp.obj" \
"CMakeFiles/TPAPG.dir/supplier.cpp.obj"

# External object files for target TPAPG
TPAPG_EXTERNAL_OBJECTS =

TPAPG.exe: CMakeFiles/TPAPG.dir/main.cpp.obj
TPAPG.exe: CMakeFiles/TPAPG.dir/service.cpp.obj
TPAPG.exe: CMakeFiles/TPAPG.dir/supplier.cpp.obj
TPAPG.exe: CMakeFiles/TPAPG.dir/build.make
TPAPG.exe: CMakeFiles/TPAPG.dir/linklibs.rsp
TPAPG.exe: CMakeFiles/TPAPG.dir/objects1.rsp
TPAPG.exe: CMakeFiles/TPAPG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Raphael\Programing\Git\TPAPG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TPAPG.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TPAPG.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TPAPG.dir/build: TPAPG.exe

.PHONY : CMakeFiles/TPAPG.dir/build

CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/main.cpp.obj.requires
CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/service.cpp.obj.requires
CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/supplier.cpp.obj.requires

.PHONY : CMakeFiles/TPAPG.dir/requires

CMakeFiles/TPAPG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TPAPG.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TPAPG.dir/clean

CMakeFiles/TPAPG.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Raphael\Programing\Git\TPAPG D:\Raphael\Programing\Git\TPAPG D:\Raphael\Programing\Git\TPAPG\cmake-build-debug D:\Raphael\Programing\Git\TPAPG\cmake-build-debug D:\Raphael\Programing\Git\TPAPG\cmake-build-debug\CMakeFiles\TPAPG.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TPAPG.dir/depend


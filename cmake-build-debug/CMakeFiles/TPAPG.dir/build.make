# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/raphael/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.4674.29/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/raphael/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.4674.29/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raphael/git/TPAPG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raphael/git/TPAPG/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TPAPG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TPAPG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TPAPG.dir/flags.make

CMakeFiles/TPAPG.dir/main.cpp.o: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raphael/git/TPAPG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TPAPG.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPAPG.dir/main.cpp.o -c /home/raphael/git/TPAPG/main.cpp

CMakeFiles/TPAPG.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raphael/git/TPAPG/main.cpp > CMakeFiles/TPAPG.dir/main.cpp.i

CMakeFiles/TPAPG.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raphael/git/TPAPG/main.cpp -o CMakeFiles/TPAPG.dir/main.cpp.s

CMakeFiles/TPAPG.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TPAPG.dir/main.cpp.o.requires

CMakeFiles/TPAPG.dir/main.cpp.o.provides: CMakeFiles/TPAPG.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TPAPG.dir/build.make CMakeFiles/TPAPG.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TPAPG.dir/main.cpp.o.provides

CMakeFiles/TPAPG.dir/main.cpp.o.provides.build: CMakeFiles/TPAPG.dir/main.cpp.o


CMakeFiles/TPAPG.dir/service.cpp.o: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/service.cpp.o: ../service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raphael/git/TPAPG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TPAPG.dir/service.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPAPG.dir/service.cpp.o -c /home/raphael/git/TPAPG/service.cpp

CMakeFiles/TPAPG.dir/service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raphael/git/TPAPG/service.cpp > CMakeFiles/TPAPG.dir/service.cpp.i

CMakeFiles/TPAPG.dir/service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raphael/git/TPAPG/service.cpp -o CMakeFiles/TPAPG.dir/service.cpp.s

CMakeFiles/TPAPG.dir/service.cpp.o.requires:

.PHONY : CMakeFiles/TPAPG.dir/service.cpp.o.requires

CMakeFiles/TPAPG.dir/service.cpp.o.provides: CMakeFiles/TPAPG.dir/service.cpp.o.requires
	$(MAKE) -f CMakeFiles/TPAPG.dir/build.make CMakeFiles/TPAPG.dir/service.cpp.o.provides.build
.PHONY : CMakeFiles/TPAPG.dir/service.cpp.o.provides

CMakeFiles/TPAPG.dir/service.cpp.o.provides.build: CMakeFiles/TPAPG.dir/service.cpp.o


CMakeFiles/TPAPG.dir/supplier.cpp.o: CMakeFiles/TPAPG.dir/flags.make
CMakeFiles/TPAPG.dir/supplier.cpp.o: ../supplier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raphael/git/TPAPG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TPAPG.dir/supplier.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPAPG.dir/supplier.cpp.o -c /home/raphael/git/TPAPG/supplier.cpp

CMakeFiles/TPAPG.dir/supplier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPAPG.dir/supplier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raphael/git/TPAPG/supplier.cpp > CMakeFiles/TPAPG.dir/supplier.cpp.i

CMakeFiles/TPAPG.dir/supplier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPAPG.dir/supplier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raphael/git/TPAPG/supplier.cpp -o CMakeFiles/TPAPG.dir/supplier.cpp.s

CMakeFiles/TPAPG.dir/supplier.cpp.o.requires:

.PHONY : CMakeFiles/TPAPG.dir/supplier.cpp.o.requires

CMakeFiles/TPAPG.dir/supplier.cpp.o.provides: CMakeFiles/TPAPG.dir/supplier.cpp.o.requires
	$(MAKE) -f CMakeFiles/TPAPG.dir/build.make CMakeFiles/TPAPG.dir/supplier.cpp.o.provides.build
.PHONY : CMakeFiles/TPAPG.dir/supplier.cpp.o.provides

CMakeFiles/TPAPG.dir/supplier.cpp.o.provides.build: CMakeFiles/TPAPG.dir/supplier.cpp.o


# Object files for target TPAPG
TPAPG_OBJECTS = \
"CMakeFiles/TPAPG.dir/main.cpp.o" \
"CMakeFiles/TPAPG.dir/service.cpp.o" \
"CMakeFiles/TPAPG.dir/supplier.cpp.o"

# External object files for target TPAPG
TPAPG_EXTERNAL_OBJECTS =

TPAPG: CMakeFiles/TPAPG.dir/main.cpp.o
TPAPG: CMakeFiles/TPAPG.dir/service.cpp.o
TPAPG: CMakeFiles/TPAPG.dir/supplier.cpp.o
TPAPG: CMakeFiles/TPAPG.dir/build.make
TPAPG: CMakeFiles/TPAPG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raphael/git/TPAPG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TPAPG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TPAPG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TPAPG.dir/build: TPAPG

.PHONY : CMakeFiles/TPAPG.dir/build

CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/main.cpp.o.requires
CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/service.cpp.o.requires
CMakeFiles/TPAPG.dir/requires: CMakeFiles/TPAPG.dir/supplier.cpp.o.requires

.PHONY : CMakeFiles/TPAPG.dir/requires

CMakeFiles/TPAPG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TPAPG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TPAPG.dir/clean

CMakeFiles/TPAPG.dir/depend:
	cd /home/raphael/git/TPAPG/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raphael/git/TPAPG /home/raphael/git/TPAPG /home/raphael/git/TPAPG/cmake-build-debug /home/raphael/git/TPAPG/cmake-build-debug /home/raphael/git/TPAPG/cmake-build-debug/CMakeFiles/TPAPG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TPAPG.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/HBat/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/HBat/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/hbat_code/cpp/helloj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/helloj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/helloj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloj.dir/flags.make

CMakeFiles/helloj.dir/main.cpp.o: CMakeFiles/helloj.dir/flags.make
CMakeFiles/helloj.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helloj.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloj.dir/main.cpp.o -c /cygdrive/d/hbat_code/cpp/helloj/main.cpp

CMakeFiles/helloj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloj.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/hbat_code/cpp/helloj/main.cpp > CMakeFiles/helloj.dir/main.cpp.i

CMakeFiles/helloj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloj.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/hbat_code/cpp/helloj/main.cpp -o CMakeFiles/helloj.dir/main.cpp.s

CMakeFiles/helloj.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/helloj.dir/main.cpp.o.requires

CMakeFiles/helloj.dir/main.cpp.o.provides: CMakeFiles/helloj.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloj.dir/build.make CMakeFiles/helloj.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/helloj.dir/main.cpp.o.provides

CMakeFiles/helloj.dir/main.cpp.o.provides.build: CMakeFiles/helloj.dir/main.cpp.o


# Object files for target helloj
helloj_OBJECTS = \
"CMakeFiles/helloj.dir/main.cpp.o"

# External object files for target helloj
helloj_EXTERNAL_OBJECTS =

helloj.exe: CMakeFiles/helloj.dir/main.cpp.o
helloj.exe: CMakeFiles/helloj.dir/build.make
helloj.exe: CMakeFiles/helloj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable helloj.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloj.dir/build: helloj.exe

.PHONY : CMakeFiles/helloj.dir/build

CMakeFiles/helloj.dir/requires: CMakeFiles/helloj.dir/main.cpp.o.requires

.PHONY : CMakeFiles/helloj.dir/requires

CMakeFiles/helloj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloj.dir/clean

CMakeFiles/helloj.dir/depend:
	cd /cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/hbat_code/cpp/helloj /cygdrive/d/hbat_code/cpp/helloj /cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug /cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug /cygdrive/d/hbat_code/cpp/helloj/cmake-build-debug/CMakeFiles/helloj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloj.dir/depend

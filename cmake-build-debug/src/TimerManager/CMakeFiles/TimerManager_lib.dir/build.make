# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/presmanes3/Descargas/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/presmanes3/Descargas/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/presmanes3/Documentos/Programming/Local/TimerManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug

# Include any dependencies generated for this target.
include src/TimerManager/CMakeFiles/TimerManager_lib.dir/depend.make

# Include the progress variables for this target.
include src/TimerManager/CMakeFiles/TimerManager_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/TimerManager/CMakeFiles/TimerManager_lib.dir/flags.make

src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o: src/TimerManager/CMakeFiles/TimerManager_lib.dir/flags.make
src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o: ../src/TimerManager/TimerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o"
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o -c /home/presmanes3/Documentos/Programming/Local/TimerManager/src/TimerManager/TimerManager.cpp

src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.i"
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/presmanes3/Documentos/Programming/Local/TimerManager/src/TimerManager/TimerManager.cpp > CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.i

src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.s"
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/presmanes3/Documentos/Programming/Local/TimerManager/src/TimerManager/TimerManager.cpp -o CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.s

# Object files for target TimerManager_lib
TimerManager_lib_OBJECTS = \
"CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o"

# External object files for target TimerManager_lib
TimerManager_lib_EXTERNAL_OBJECTS =

src/TimerManager/libTimerManager_lib.a: src/TimerManager/CMakeFiles/TimerManager_lib.dir/TimerManager.cpp.o
src/TimerManager/libTimerManager_lib.a: src/TimerManager/CMakeFiles/TimerManager_lib.dir/build.make
src/TimerManager/libTimerManager_lib.a: src/TimerManager/CMakeFiles/TimerManager_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTimerManager_lib.a"
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && $(CMAKE_COMMAND) -P CMakeFiles/TimerManager_lib.dir/cmake_clean_target.cmake
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TimerManager_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/TimerManager/CMakeFiles/TimerManager_lib.dir/build: src/TimerManager/libTimerManager_lib.a

.PHONY : src/TimerManager/CMakeFiles/TimerManager_lib.dir/build

src/TimerManager/CMakeFiles/TimerManager_lib.dir/clean:
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager && $(CMAKE_COMMAND) -P CMakeFiles/TimerManager_lib.dir/cmake_clean.cmake
.PHONY : src/TimerManager/CMakeFiles/TimerManager_lib.dir/clean

src/TimerManager/CMakeFiles/TimerManager_lib.dir/depend:
	cd /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/presmanes3/Documentos/Programming/Local/TimerManager /home/presmanes3/Documentos/Programming/Local/TimerManager/src/TimerManager /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager /home/presmanes3/Documentos/Programming/Local/TimerManager/cmake-build-debug/src/TimerManager/CMakeFiles/TimerManager_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/TimerManager/CMakeFiles/TimerManager_lib.dir/depend


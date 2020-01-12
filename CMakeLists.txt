cmake_minimum_required(VERSION 3.15)

# Project Name
project(TimerManagerProject_lib)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# Include root directory
include_directories(..)

set(SOURCE_FILES
        main.cpp)

# Create executable named TimerManager with SOURCE_FILES
add_executable(main ${SOURCE_FILES})

# Set Directories to be included
set(DIRECTORIES
        src)

# Include directory SoftwareTimer
include_directories(${DIRECTORIES})

# Also add subdirectories inside src
add_subdirectory(src)
add_subdirectory(UnitTest)
add_subdirectory(Examples)

# Link libraries to executable files
target_link_libraries(main ${LIBRARIES})
cmake_minimum_required(VERSION 3.15)

# Project Name
project(TimerManagerProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# Include root directory
include_directories(..)

# Set Directories to be included
set(DIRECTORIES
        src)

# Include directory SoftwareTimer
include_directories(${DIRECTORIES})

# Also add subdirectories inside src
add_subdirectory(src)
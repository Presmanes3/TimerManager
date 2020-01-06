cmake_minimum_required(VERSION 3.15)

# Project Name
project(TimerManagerProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

# Create executable named TimerManager with SOURCE_FILES
add_executable(TimerManagerProject ${SOURCE_FILES})

# Include root directory
include_directories(.)

# Set Directories to be included
set(DIRECTORIES
        SoftwareTimer
        TimerManager
        UnitTest)

# Include directory SoftwareTimer
include_directories(${DIRECTORIES})

# Include subdirectories CmakeLists.txt
add_subdirectory(SoftwareTimer)
add_subdirectory(TimerManager)
add_subdirectory(UnitTest)

# Set libraries Variables
set(LIBRARIES
        SoftwareTimer_lib
        TimerManager_lib)

target_link_libraries(TimerManagerProject $(LIBRARIES))




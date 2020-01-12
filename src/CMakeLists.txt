cmake_minimum_required(VERSION 3.15)

# Project Name
project(main)

# C++ Standard
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp)

# Create executable named TimerManager with SOURCE_FILES
add_executable(main ${SOURCE_FILES})



# Include root directory
include_directories(..)

# Set Directories to be included
set(DIRECTORIES
        Timer
        TimerManager
        UnitTest
        Examples)

add_custom_target(Constants_lib SOURCES TimerManagerConstants.h)

# Include directory SoftwareTimer
include_directories(${DIRECTORIES})

# Include subdirectories CmakeLists.txt
add_subdirectory(Timer)
add_subdirectory(TimerManager)
add_subdirectory(UnitTest)
add_subdirectory(Examples)

# Set libraries Variables
set(LIBRARIES
        Timer_lib
        TimerManager_lib)

# Link libraries to executable files
target_link_libraries(main ${LIBRARIES})
target_link_libraries(TimerManagerUse_Example_Exec ${LIBRARIES})
target_link_libraries(TimerUse_Example_Exec ${LIBRARIES})








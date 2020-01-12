# Project Name
project(TimerManager_src)

set(TIMER_MANAGER_HEADER
        TimerManager.h)

set(TIMER_MANAGER_SOURCE
        TimerManager.cpp)

# TimerManager_lib
add_library(TimerManager_lib STATIC ${TIMER_MANAGER_SOURCE} ${TIMER_MANAGER_HEADER})

set(TIMER_HEADER
        Timer.h)

set(TIMER_SOURCE
        Timer.cpp)

# Timer_lib
add_library(Timer_lib STATIC ${TIMER_SOURCE} ${TIMER_HEADER})

# Set libraries Variables
set(LIBRARIES
        Timer_lib
        TimerManager_lib)











# Project Name
project(TimerManager_src)

set(TimerController_headers
        TimerManager.h
        Timer.h)

set(TimerController_sources
        TimerManager.cpp
        Timer.cpp)

# Timer_lib
add_library(TimerController_lib STATIC ${TimerController_sources} ${TimerController_headers})

# Set libraries Variables
set(LIBRARIES
        TimerController_lib)











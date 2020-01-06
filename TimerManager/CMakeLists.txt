project(TimerManager)

set(HEADER_FILES
        TimerManager.h)

set(SOURCE_FILES
        TimerManager.cpp)

# TimerManager_lib is the name of the library which contains TimerManager.h/.cpp
add_library(TimerManager_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})


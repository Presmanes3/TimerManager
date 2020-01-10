project(BasicTimer)

set(HEADER_FILES
        Timer.h)

set(SOURCE_FILES
        Timer.cpp)

# Timer_lib is the name of the library which contains Timer.h/.cpp
add_library(Timer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

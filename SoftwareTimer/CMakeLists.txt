project(SoftwareTimer)

set(HEADER_FILES
        SoftwareTimer.h)

set(SOURCE_FILES
        SoftwareTimer.cpp)

# SoftwareTimer_lib is the name of the library which contains SoftwareTimer.h/.cpp
add_library(SoftwareTimer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})


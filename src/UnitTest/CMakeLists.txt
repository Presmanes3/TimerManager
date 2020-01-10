project(TimerManagerUnitTest)

# Add lib Cmake file
add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Test Files contain all test.cpp which must be executed
set(TEST_FILES
        TimerTest.cpp
        TimerManagerTest.cpp)

# Test Libraries contain libraries for testing
set(TEST_LIBRARIES
        Timer_lib
        TimerManager_lib)

# The google test will be Test1.cpp
add_executable(Google_Tests_run ${TEST_FILES})

# Link test Libraries
target_link_libraries(Google_Tests_run ${TEST_LIBRARIES})

# Link gtest libraries
target_link_libraries(Google_Tests_run gtest gtest_main)
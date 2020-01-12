project(TimerManager_Examples)

add_custom_target(TimerUse_Example SOURCES TimerUse_Example.cpp)
add_custom_target(TimerManagerUse_Example SOURCES TimerManagerUse_Example.cpp)

# Executable for TimerManager Example
add_executable(TimerManagerUse_Example_Exec TimerManagerUse_Example.cpp)

# Executable for Timer Example
add_executable(TimerUse_Example_Exec TimerUse_Example.cpp)


# Link libraries
target_link_libraries(TimerManagerUse_Example_Exec ${LIBRARIES})
target_link_libraries(TimerUse_Example_Exec ${LIBRARIES})
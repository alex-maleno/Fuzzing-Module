project(drone)
add_executable(drone main.cpp maneuvers.cpp specs.cpp sys_status.cpp)
add_executable(specs-slice specs-slice.cpp specs.cpp)
cmake_minimum_required (VERSION 2.6)
project (led_daemon)
add_executable(led_daemon main.cpp main.cpp leds.cpp ledstrip.cpp animation.cpp)
target_link_libraries(led_daemon rt pthread)
install (TARGETS led_daemon DESTINATION bin)


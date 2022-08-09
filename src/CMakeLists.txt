
# * SPDX-License-Identifier: BSD-3-Clause
# * Copyright 2022 NXP

cmake_minimum_required (VERSION 2.6)
project (led_animation_manager)
add_executable(led_animation_manager main.cpp leds.cpp ledstrip.cpp animation.cpp)
target_link_libraries(led_animation_manager rt pthread)
SET(CMAKE_INSTALL_PREFIX ../deploy CACHE STRING " " FORCE)
install (TARGETS led_animation_manager DESTINATION ./)
install (FILES animations.conf DESTINATION ./)
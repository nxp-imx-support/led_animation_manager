
# * SPDX-License-Identifier: BSD-3-Clause
# * Copyright 2022 NXP

cmake_minimum_required (VERSION 2.6)
project (set_animation)
add_executable(set_animation set_animation.c)
target_link_libraries(set_animation rt)
SET(CMAKE_INSTALL_PREFIX ../deploy CACHE STRING " " FORCE)
install (TARGETS set_animation DESTINATION ./)
install (FILES ../src/animations/IDLE DESTINATION ./)
install (FILES ../src/animations/LISTENING DESTINATION ./)
install (FILES ../src/animations/RENDER DESTINATION ./)
install (FILES ../src/animations/SPEAKING DESTINATION ./)
install (FILES ../src/animations/THINKING DESTINATION ./)
install (FILES ../src/animations/START DESTINATION ./)

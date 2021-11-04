cmake_minimum_required (VERSION 2.6)
project (sendAlexaMsgQ)
add_executable(sendAlexaMsgQ sendAlexaMsgQ.c)
target_link_libraries(sendAlexaMsgQ rt)
install (TARGETS sendAlexaMsgQ DESTINATION bin)


First commit for LED Daemons annimation

To compile project first setup your toolchain, then
$CXX -o test main.cpp leds.cpp ledstrip.cpp animation.cpp -lrt -lpthread
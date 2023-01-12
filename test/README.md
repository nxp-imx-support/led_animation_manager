# set_animation Commands Sender Test Application

The set_animation is a simple application that can send messages to the
led_animation_manager.

## Valid messages

- IDLE
- START
- RENDER
- LISTENING
- SPEAKING
- THINKING

## Examples of usage

To test, type next command:

    ./set_animation RENDER


To change the current animation:

    ./set_animation SPEAKING

To turn off the current animation:

    ./set_animation IDLE


## Build instructions

- Create a build directory:
```
    mkdir build
    cd build
```
- Run the cmake:
```
    cmake ../
    make
```
The output file should be the set_animation executable 

- Install the set_animation app on local target directory:
```
    make install
```

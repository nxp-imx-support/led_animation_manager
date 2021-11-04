# Message-Queue Commands Sender Test Application

The sendMessageQ is a simple application that can send messages to test the
DisplayCards application. The DisplayCards is always listening to the MessageQ
channel opened by te sendMessageQ test application.

## Valid messages

- RENDER
- IDLE
- LISTENING
- SPEAKING

## Examples of usage

To Render the json file pointed by template.json

    ./sendMessageQ RENDER


To hide the current Display Card

    ./sendMessageQ SPEAKING
    ./sendMessageQ IDLE


## Build instructions

- Create a build directory

    mkdir build
    cd build

- Run the cmake

    cmake ../
    make

The output file should be the sendMessageQ executable 

- Install the sendMessageQ app on local target directory

    make install

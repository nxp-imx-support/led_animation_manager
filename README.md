# Led_Animation_Manager project

To compile project in standalone environment first setup your toolchain:

```
source /opt/fsl-imx-xwayland/5.10-hardknott/environment-setup-cortexa53-crypto-poky-linux
```


```
mkdir build
cd build
cmake ../
make install
```
Outputs `led_animation_manager` and `set_animation` are in `/build`. And for to test in the board, you need take both files `led_animation_manager` and `set_animation` in addition of animation files located at `/src/animations`.

Once copied to your board, now you can execute your animation with next example commands:

    ./led_animation_manager &
    ./test START


### How to build your own animations
1. Build a new `.txt` animation file, like `EXAMPLE`
2. Take in care the nex format to build your animations, dropping comments:
    
     Time_in_mSeconds   RGB_LED1     RGB_LED2     RGB_LED3     RGB_LED4   
     ```
        100             182 52 255   197 52 255   222 52 255   255 52 101
        .               .   .   .     .   .  .     .   .   .    .   .  .
        .               .   .   .     .   .  .     .   .   .    .   .  .
        .               .   .   .     .   .  .     .   .   .    .   .  .
        100             255 52 101   182 52 255   197 52 255   222 52 255
    ```
3. Once build, save it and add it to the list insigh of `animations.conf` and ready!
    
    Now you can execute your animation with next commands:
    
    ```
    ./led_animation_manager &
    ./test EXAMPLE
    ```
### Note:

As additional information, **led_animation_manager** is an application that handles its LEDs light effects based on **PCA9955BTW** driver. This device driver reach handle until **16 I/O signals**.

For this case, the **8MIC-RPI-MX8** hat board just command four LEDs(4*3 = 12 signals), but you can custom the amount signal outs. This can be custome from the file `/src/leds.conf`

For this example, you can find there, how you can enable the different signal outputs for command the LEDs. So you can take them as example of how to anable more signal outputs for your custom projects. 

As an example, we take the first three outputs that controls the first LED:
```
/sys/class/leds/pca995x:red0/brightness
/sys/class/leds/pca995x:green0/brightness
/sys/class/leds/pca995x:blue0/brightness
```
And the another three LEDs just change in index number for each of them.

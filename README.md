# Led_Animation_Manager project

To compile project in standalone environment first setup your toolchain, by this case we used next one:

```
source /opt/fsl-imx-xwayland/5.10-hardknott/environment-setup-cortexa53-crypto-poky-linux
```
After that, must to prepare, and install with next commands:

```
mkdir build
cd build
cmake ../
make install
```
Outputs will a level back at `/deploy` that was generated with all necessary files for testing board (`led_animation_manager, set_animation, animations.conf, leds.conf`, and animations files like `IDLE, START, LISTENING, RENDER, SPEAKING` and `THINKING`. 

Knowing that, we must pick up all `/deploys` contend and bring it to the board.
In next step, before board boots, we must get inside `U-boot` to change for the right Device Tree by to command the `8MIC-RPI-MX8` hat EVK board `Rev E`. Then, once inside of `U-boot`, we must type next commands:

```
edit fdtfile
imx8mn-evk-8mic-revE.dtb
saveenv
boot
```

Once, with booted board and all files copied in it. The next step is to load the Kernel module of LEDs control with next command:

`modprobe leds-pca995x`

NOTE: the `leds-pca995x` module is coming inside from BSP Linux version `5.15.52`. For earlier versions you must bring it by yourself.

After that, execute rights must be granted to the executable files:

```
chmod +x led_animation_manager
chmod +x set_animation
```

Finally, now you can execute your animation with next example commands:

```
./led_animation_manager &
./set_animation START
```

NOTE: once led_animation_manager is running, you can execute different animations by changing the argument of `set_animation`, like: 

`./set_animation <name_animation_file>`

### How to build your own custom animations

1. Build a new `.txt` animation file, like `EXAMPLE`
2. Take in care the next format to build your animations, dropping comments:
    
     Time_in_mSeconds   RGB_LED1     RGB_LED2     RGB_LED3     RGB_LED4   
     ```
        100             182 52 255   197 52 255   222 52 255   255 52 101
        .               .   .   .     .   .  .     .   .   .    .   .  .
        .               .   .   .     .   .  .     .   .   .    .   .  .
        .               .   .   .     .   .  .     .   .   .    .   .  .
        100             255 52 101   182 52 255   197 52 255   222 52 255
    ```
3. Once build, save it and add it to the list inside of `animations.conf` and ready!
    
    Now you can execute your animation with next commands:
    
    ```
    ./led_animation_manager &
    ./set_animation EXAMPLE
    ```
### Note:

As additional information, `led_animation_manager` is an application that handles its LEDs light effects from `leds.conf`. The `leds.conf` file in specific is based on `PCA9955BTW` driver. This device driver reach handle until `16 I/O signals`.

For this case, the `8MIC-RPI-MX8` hat board just command four LEDs(`4*3 = 12 signals`), but you can custom the amount signal outs. This can be custom from the file `leds.conf`

For this example, you can find there, how you can enable the different signal outputs for command the LEDs. So you can take them as example of how to enable more signal outputs for your custom projects. 

As an example, we take the first three outputs that controls the first LED:
```
/sys/class/leds/pca995x:red0/brightness
/sys/class/leds/pca995x:green0/brightness
/sys/class/leds/pca995x:blue0/brightness
```
And the another three LEDs just change in index number for each of them.


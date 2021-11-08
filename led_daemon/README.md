## LED Daemons animation project

To compile project first setup your toolchain like

```
source /opt/fsl-imx-xwayland/5.10-hardknott/environment-setup-cortexa53-crypto-poky-linux

```


```
cd led_daemon
mkdir build
cd build
cmake ../
make

```

Output is build/led_daemon

Also compile the sendAlexaMsgQ

```
cd led_daemon/sendAlexaMsqQ
mkdir build
cd build
cmake ../
make

```



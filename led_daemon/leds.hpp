/*
 * Copyright 2021 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef LEDS_H
#define LEDS_H

#include <iostream>
#include<fstream>

class LED{
private:
    std::string led_path;
    std::fstream fs_brightness;

public:
    void open();
    void open(std::string path);
    void close();
    void setBrightness(int);
    int getBrightness();
    
    LED(std::string path = "");
};

#endif
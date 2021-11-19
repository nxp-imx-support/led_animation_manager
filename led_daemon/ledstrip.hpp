/*
 * Copyright 2021 NXP
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include "leds.hpp"
#include <vector>

typedef std::vector<LED> LED_STRIP_CONTAINER;

class LEDSTRIP: public LED_STRIP_CONTAINER{
private:
    std::fstream confFile;

public:
    LEDSTRIP();
    LEDSTRIP(const char * confpath);
    void setBrightnessLED(int, int ) ; 
    void open(int, std::string);
    void setBrightness(int);
};

#endif 
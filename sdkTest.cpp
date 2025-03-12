#include "pico/stdlib.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include "pico/time.h"
#include "pico/platform.h"

#include "common/pimoroni_common.hpp"
#include "badger2040.hpp"

using namespace pimoroni;
Badger2040 badger;

int main()
{
    stdio_init_all();

    badger.init();
    badger.update_speed(1);
    badger.pen(15);
    badger.thickness(1);
    badger.clear();
    badger.pen(0);
    badger.font("bitmap8");
    badger.text("Hello World", 10, 10);
    badger.text("Press any button...", 10, 30);
    badger.update();
    printf("first update was done ...waiting for button press\n");
    badger.wait_for_press();

    badger.clear();
    badger.pen(15);
    if (badger.pressed(badger.A)) badger.text("Button A pressed", 10, 10);
    else if (badger.pressed(badger.B)) badger.text("Button B pressed", 10, 10);
    else if (badger.pressed(badger.C)) badger.text("Button C pressed", 10, 10);
    else if (badger.pressed(badger.DOWN)) badger.text("Button DOWN pressed", 10, 10);
    else if (badger.pressed(badger.UP)) badger.text("Button UP pressed", 10, 10);
    badger.update();
    badger.wait_for_press();

}

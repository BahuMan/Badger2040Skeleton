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

struct morcel_t {
    char text[240]; //at size 2, this many characters fit. However, word-wrap means you'll have less screen available
    char promptA[10];
    char promptB[10];
    char promptC[10];
    int  indexA;
    int  indexB;
    int  indexC;
};

morcel_t story[10] {
    {"this is a test", "A", "mid", "end", 1, 5, 8},
    {"second text", "back", "start", "next", 0, 0, 2},
    {"third text", "back", "start", "next", 1, 0, 3},
    {"fourth text", "back", "start", "next", 2, 0, 4},
    {"fifth text", "back", "start", "next", 3, 0, 5},
    {"sixth text", "back", "start", "next", 4, 0, 6},
    {"seventh text", "back", "start", "next", 5, 0, 7},
    {"eighth text", "back", "start", "next", 6, 0, 8},
    {"this is a bigger block of text. "
        "Let's see how much text we can squeeze "
        "onto this badger2024 "
        "and how many lines we have "
        "to create a small morcel "
        "of story in this interactive "
        "e-book", "back", "start", "fifth", 7, 0, 4},
};

int waitForChoice(int i) {
    badger.pen(0);
    badger.text(story[i].promptA, 20, 114, 2.0F);
    badger.text(story[i].promptB, 140 - 3*strlen(story[i].promptB), 114, 2.0F);
    badger.text(story[i].promptC, 240 - 3*strlen(story[i].promptC), 114, 2.0F);
    badger.pen(8);
    badger.line(0, 113, 296, 113);
    badger.line(100, 114, 100, 128);
    badger.line(200, 114, 200, 128);
    badger.update();
    while (1) {
        badger.wait_for_press();
        if (badger.pressed(badger.A)) {
            return story[i].indexA;
        }
        else if (badger.pressed(badger.B)) {
            return story[i].indexB;
        }
        else if (badger.pressed(badger.C)) {
            return story[i].indexC;
        }
    }

}

int main()
{
    stdio_init_all();
    badger.init();
    busy_wait_ms(1000);
    badger.update_speed(1);

    badger.font("bitmap6");
    int current_morcel = 0;
    badger.pen(15);
    badger.clear();
    badger.pen(0);
    badger.text("Choice...", 0, 0, 2.0F);
    busy_wait_ms(2000);

    while (1) {
        printf("index %d, len %d:\n", current_morcel, strlen(story[current_morcel].text));
        printf(story[current_morcel].text);

        badger.pen(15);
        badger.clear();
        badger.pen(0);
        badger.text(story[current_morcel].text, 0, 0, 2.0F);
        current_morcel = waitForChoice(current_morcel);
    }

}

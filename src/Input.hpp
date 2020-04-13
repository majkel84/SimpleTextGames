#pragma once

#include <termios.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

enum enumDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

void input_enter_off(void);
void input_enter_on(void);
//enum Direction get_input(void);

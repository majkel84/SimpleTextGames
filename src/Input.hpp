#pragma once

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <GameField.hpp>

using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    UPLEFT,
    UPRIGHT,
    DOWNLEFT,
    DOWNRIGHT,
    ERROR = -1
};

void inputEnterOff();
//void inputEnterOn();
enum Direction getInput(char user_input);
char timeDelay();

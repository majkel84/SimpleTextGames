#pragma once

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ERROR
};

void inputEnterOff();
void inputEnterOn();
enum Direction getInput();

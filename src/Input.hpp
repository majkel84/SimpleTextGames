#pragma once

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <semaphore.h>

using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ERROR = -1
};

void inputEnterOff();
void inputEnterOn();
enum Direction getInput();

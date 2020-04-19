#pragma once

enum class BoardField : char
{
    X = 'X',
    O = 'O',
    UNKNOWN = '*',
    SNAKEHEADRIGHT = '>',
    SNAKEHEADLEFT = '<',
    SNAKEHEADUP = '^',
    SNAKEHEADDOWN = 'V',
    SNAKEBODY = 'o',
    SNAKEBOARD = '.',
    BLANK = ' '
};

#define INITIAL_SNAKE_LENGTH 3
#define TIME_DELAY 1000 * 300

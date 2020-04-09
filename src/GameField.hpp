#pragma once

#include <map>
#include <memory>

enum class BoardField : char
{
    X = 'X',
    O = 'O',
    UNKNOWN = '*',
    SNAKEHEAD = '0',
    SNAKEBODY = 'o',
    WALL = '#',
    BLANK = ' '
};

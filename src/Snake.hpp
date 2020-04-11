#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>
#include <curses.h>

using namespace std;

class Snake
{
public:
    void setup();
    void setStartPosition();
    void putFruitOnBoard();
    void input();
    void show();
    void drawHorizontalBorder();
    void drawVerticalBorder();
    void logic();

private:
    bool gameOver = false;
    const unsigned short width = 5;
    const unsigned short height = 5;
    unsigned short snakeX, snakeY;
    unsigned short fruitX,fruitY;
    enum enumDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    enumDirection direction = STOP;
    unsigned short score = 0;
};

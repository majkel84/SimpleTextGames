#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>

using namespace std;

class Snake
{
    void setup();
    void setStartPosition();
    void putFruitOnBoard();
    void input();
    void show();
    void logic();

private:
    bool gameOver = false;
    const unsigned short width = 20;
    const unsigned short height = 20;
    unsigned short snakeX, snakeY;
    unsigned short fruitX,fruitY;
    enum enumDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    enumDirection direction = STOP;
};

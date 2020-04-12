#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>
#include <curses.h>

using namespace std;

class Snake : public GameBoard
{
public:
    Snake();
    void setup();
    void setStartPosition();
    void putFruitOnBoard();
    void drawBoard();
    void clearBoard();

private:
    bool gameOver = false;
    const unsigned short width = 5;
    const unsigned short height = 5;
    pair <unsigned short, unsigned short> snakePosition;
    pair <unsigned short, unsigned short> fruitPosition;
    enum enumDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    enumDirection direction = STOP;
    unsigned short score = 0;
};

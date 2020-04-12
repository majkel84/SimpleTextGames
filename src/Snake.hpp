#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>
#include <curses.h>

using namespace std;

class Snake : public GameBoard
{
public:
    Snake(int numberOfFields, char boardDefaultField);
    void setup();
    void setStartPosition();
    void putFruitOnBoard();
    void drawBoard();
    void clearBoard();
    void updateScore();

private:
    bool gameOver = false;
    bool snakeFoodEaten = false;
    int boardSize;
    int snakeLength = INITIAL_SNAKE_LENGTH;
    pair <unsigned short, unsigned short> snakePosition;
    pair <unsigned short, unsigned short> fruitPosition;
    enum enumDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    enumDirection direction = STOP;
    unsigned short score = INITIAL_SNAKE_LENGTH;
};

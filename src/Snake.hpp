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
    int getScore();

private:
    bool gameOver = false;
    bool snakeFoodEaten = true;
    int boardSize;
    vector <pair <int, int>> snake;
    int snakeLength = INITIAL_SNAKE_LENGTH;
    pair <unsigned short, unsigned short> snakePosition;
    pair <unsigned short, unsigned short> fruitPosition;
};

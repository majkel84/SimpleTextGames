#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>
#include <Input.hpp>
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
    enum Direction getDirection();

private:
    bool gameOver = false;
    bool snakeFoodEaten = true;
    int boardSize;
    vector <pair <int, int>> snake;
    int snakeLength = INITIAL_SNAKE_LENGTH;
    char actualSNakeHeadDirection = (char)BoardField::SNAKEHEADRIGHT;
    pair <unsigned short, unsigned short> fruitPosition;
    sem_t snake_sema;
    enum Direction direction;
};

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
    void updateNextDirection(enum Direction direct);
    void updateSnakeHeadDirection();
    void updateSnakeHeadNextDirection(enum Direction direction);

private:
    bool gameOver = false;
    bool snakeFoodEaten = false;
    int boardSize;
    vector <pair <int, int>> snake;
    int snakeLength = INITIAL_SNAKE_LENGTH;
    char actualSNakeHeadDirection = (char)BoardField::SNAKEHEADRIGHT;
    pair <unsigned short, unsigned short> fruitPosition;
    enum Direction direction = RIGHT;
    enum Direction nextDirection;
};

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
    void snakeGameOver();
    enum Direction getDirection();
    void updateDirection(Direction direct);
    enum Direction validateDirection(Direction direction);
    void updateSnakeHeadDirection();
    void updateSnakeMove();
    void updateSnakePosition(short x, short y);

private:
    bool gameOver = false;
    bool snakeFoodEaten = false;
    int boardSize;
    vector <pair <int, int>> snake;
    int snakeLength = INITIAL_SNAKE_LENGTH;
    char actualSNakeHeadDirection = (char)BoardField::SNAKEHEADRIGHT;
    pair <unsigned short, unsigned short> fruitPosition;
    enum Direction direction = RIGHT;
};

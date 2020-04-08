#pragma once

#include <GameField.hpp>
#include <GameBoard.hpp>

using namespace std;

class Snake
{
    void logic();
    void setup();
    void input();
    void show();

private:
    bool gameOver = false;
};

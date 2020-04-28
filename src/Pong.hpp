#pragma once

#include <GameBoard.hpp>
#include <GameField.hpp>

using namespace std;

class Pong : public GameBoard
{
public:
    Pong();
    void showBoard();
    void setBallOnBoard();
private:
    unsigned short actualPaddlePosition = 0;
    pair <unsigned,unsigned> ballPosition;
};

class Padle
{
public:
    unsigned short setPadleStartPosition(int gameBoardHeight);
private:
    const unsigned short paddleSize = 5;
};

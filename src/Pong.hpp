#pragma once

#include <GameBoard.hpp>
#include <GameField.hpp>
#include <Input.hpp>

using namespace std;

class Pong : public GameBoard
{
public:
    Pong();
    void showBoard();
    void setBallOnBoard(unsigned posX, unsigned posY);
private:
    unsigned short actualPaddlePosition = 0;
    pair <unsigned,unsigned> ballPosition;
    enum Direction ballDirection = RIGHT;
};

class Padle
{
public:
    unsigned short setPadleStartPosition(int gameBoardHeight);
private:
    const unsigned short paddleSize = 5;
};

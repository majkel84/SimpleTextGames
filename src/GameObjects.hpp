#pragma once

#include <iostream>
#include <utility>
#include <GameBoard.hpp>
#include <GameField.hpp>
#include <Input.hpp>

using namespace std;

class GameObjects
{
public:
    virtual pair <unsigned, unsigned> getPosition();

protected:
    pair <unsigned, unsigned> position;
};

class Padle : public GameObjects
{
public:
    unsigned short setPadlePosition(int padlePosition);
    unsigned short getPadleSize();
    bool checkIsPadleOnBoard(short move, short player);
private:
    const unsigned short paddleSize = 5;
};

class Ball : public GameObjects
{
public:
    void setBallPosition(pair<short, short> position);
    pair <unsigned, unsigned> getPosition();
    pair <short, short> updateBallMovement(enum Direction direction);
    enum Direction updateBallDirection(enum Direction direction);
};

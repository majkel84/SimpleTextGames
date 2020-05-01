#pragma once

#include <utility>

using namespace std;

class GameObjects
{
protected:
    pair <unsigned, unsigned> position;
};

class Padle : public GameObjects
{
public:
    unsigned short setPadleStartPosition(int gameBoardHeight);
    unsigned short getPadleSize();
private:
    const unsigned short paddleSize = 5;
};

class Ball : public GameObjects
{
public:
    pair <unsigned, unsigned> setBallPosition(unsigned posX, unsigned posY);
    pair <unsigned, unsigned> getBallPosition();
};

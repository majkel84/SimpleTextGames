#pragma once

#include <iostream>
#include <utility>

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
private:
    const unsigned short paddleSize = 5;
};

class Ball : public GameObjects
{
public:
    pair <unsigned, unsigned> setBallPosition(unsigned posX, unsigned posY);
    pair <unsigned, unsigned> getPosition();
};
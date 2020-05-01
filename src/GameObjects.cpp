#include "GameObjects.hpp"

unsigned short Padle::setPadlePosition(int gameBoardHeight)
{
    return position.first = gameBoardHeight / 2 - paddleSize / 2;
}

unsigned short Padle::getPadleSize()
{
    return paddleSize;
}

pair <unsigned, unsigned> Ball::setBallPosition(unsigned posX, unsigned posY)
{
    position.first = posX;
    position.second = posY;
}

pair <unsigned, unsigned> Ball::getBallPosition()
{
    return position;
}

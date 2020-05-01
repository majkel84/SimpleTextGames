#include "GameObjects.hpp"

pair <unsigned, unsigned> GameObjects::getPosition()
{
    return position;
}

unsigned short Padle::setPadlePosition(int padlePosition)
{
    return position.first = padlePosition - paddleSize / 2;
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

pair <unsigned, unsigned> Ball::getPosition()
{
    return position;
}

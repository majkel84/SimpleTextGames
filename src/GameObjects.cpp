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

void Ball::setBallPosition(pair <short, short> position)
{
    this -> position.first += position.first;
    this -> position.second += position.second;
    cout << this -> position.first << endl;
    cout << this -> position.second << endl;
}

pair <unsigned, unsigned> Ball::getPosition()
{
    return position;
}

pair<short, short> Ball::updateBallMovement(Direction direction)
{
    switch (direction) {
    case LEFT:
        return make_pair(0, -1);
        break;
    case RIGHT:
        return make_pair(0, 1);
        break;
    case UP:
        return make_pair(-1, 0);
        break;
    case DOWN:
        return make_pair(1, 0);
        break;
    case UPLEFT:
        return make_pair(-1, -1);
        break;
    case UPRIGHT:
        return make_pair(-1, 1);
        break;
    case DOWNLEFT:
        return make_pair(1, -1);
        break;
    case DOWNRIGHT:
        return make_pair(1, 1);
        break;
    default:
        break;
    }
    return make_pair(0, 0);
}

enum Direction Ball::updateBallDirection(Direction direction)
{
    switch (direction) {
    case UPRIGHT:
        return DOWNRIGHT;
        break;
    case UPLEFT:
        return DOWNLEFT;
        break;
    case DOWNRIGHT:
        return UPRIGHT;
        break;
    case DOWNLEFT:
        return UPLEFT;
        break;
    default:
        break;
    }
    return direction;
}

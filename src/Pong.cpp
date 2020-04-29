#include "Pong.hpp"

Pong::Pong()
{
    Padle padle;
    actualPaddlePosition = padle.setPadleStartPosition(gameBoard.size());
    Pong::setBallOnBoard(gameBoard.size() / 2, gameBoard[0].size() / 2);
    GameBoard::setBoardField(ballPosition.first, ballPosition.second,(char)BoardField::BALL);
    score = make_pair(0, 0);
}

void Pong::showBoard()
{
    GameBoard::showBoard();
}

void Pong::setBallOnBoard(unsigned posX, unsigned posY)
{
    ballPosition.first = posX;
    ballPosition.second = posY;
}

void Pong::setBallDirection(enum Direction newDirection)
{
    ballDirection = newDirection;
}

pair<unsigned, unsigned> Pong::getScore()
{
    return score;
}

void Pong::updateScore(unsigned player)
{
    switch (player) {
    case 1:
        score.first++;
        break;
    case 2:
        score.second++;
        break;
    default:
        break;
    }
}

unsigned short Padle::setPadleStartPosition(int gameBoardHeight)
{
    return gameBoardHeight / 2 - paddleSize / 2;
}

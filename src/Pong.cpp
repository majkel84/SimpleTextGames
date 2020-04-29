#include "Pong.hpp"

Pong::Pong()
{
    Padle padle;
    actualPaddlePosition = padle.setPadleStartPosition(gameBoard.size());
    Pong::setBallOnBoard(gameBoard.size() / 2, gameBoard[0].size() / 2);
    GameBoard::setBoardField(ballPosition.first, ballPosition.second,(char)BoardField::BALL);
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

unsigned short Padle::setPadleStartPosition(int gameBoardHeight)
{
    return gameBoardHeight / 2 - paddleSize / 2;
}

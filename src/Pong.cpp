#include "Pong.hpp"

Pong::Pong()
{
    Padle padle;
    actualPaddlePosition = padle.setPadleStartPosition(gameBoard.size());
    ballPosition.first = gameBoard.size() / 2;
    ballPosition.second = gameBoard[0].size() / 2;
    GameBoard::setBoardField(ballPosition.first, ballPosition.second,(char)BoardField::BALL);
}

void Pong::showBoard()
{
    GameBoard::showBoard();
}

void Pong::setBallOnBoard()
{

}

unsigned short Padle::setPadleStartPosition(int gameBoardHeight)
{
    return gameBoardHeight / 2 - paddleSize / 2;
}

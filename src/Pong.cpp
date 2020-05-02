#include "Pong.hpp"

Pong::Pong()
{
    actualPaddleOnePosition = p1.setPadlePosition(gameBoard.size() / 2);
    actualPaddleTwoPosition = actualPaddleOnePosition;
    ball.setBallPosition(gameBoard.size() / 2, gameBoard[0].size() / 2  );
    GameBoard::setBoardField(ball.getPosition(),(char)BoardField::BALL);
    score = make_pair(0, 0);
}

void Pong::setup()
{
    showBoard();
    updatePadlePosition(3);
    showBoard();
}

void Pong::showBoard()
{
    Pong::showScore();
    Pong::setPadle();
    GameBoard::showBoard();
}

void Pong::clearColumn(short columnNumber)
{
    for (auto it = 1; it < gameBoard.size() - 1; it++)
        GameBoard::setBoardField(it, columnNumber, (char)BoardField::SNAKEBOARD);
}

void Pong::setPadle()
{
    Pong::clearColumn(0);
    Pong::clearColumn(gameBoard[0].size() - 1);
    for (auto it = 0; it < p1.getPadleSize(); it++)
    {
        GameBoard::setBoardField(actualPaddleOnePosition + it, 0, (char)BoardField::PADLE);
        GameBoard::setBoardField(actualPaddleTwoPosition + it, gameBoard[0].size() - 1, (char)BoardField::PADLE);
    }
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

void Pong::showScore()
{
    cout << "PLAYER 1 - " << score.first << " : PLAYER 2 - " << score.second << '\n';
}

void Pong::updatePadleMove(Direction direction)
{
    switch (direction)
    {
    case UP:
        updatePadlePosition(-1);
        break;
    case DOWN:
        updatePadlePosition(1);
        break;
    default:
        break;
    }
}

void Pong::updatePadlePosition(short y)
{
    if (Pong::checkIsPadleOnBoard(y))
    {
        actualPaddleOnePosition += y;
        setPadle();
    }
}

bool Pong::checkIsPadleOnBoard(short move)
{
    return actualPaddleOnePosition + move > 0
            ? (actualPaddleOnePosition + move + p1.getPadleSize() < gameBoard.size()
               ? true : false)
            : false;
}

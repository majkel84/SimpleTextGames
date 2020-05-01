#include "Pong.hpp"

Pong::Pong()
{
    actualPaddleOnePosition = p1.setPadlePosition(gameBoard.size() / 2);
    actualPaddleTwoPosition = actualPaddleOnePosition;
    ball.setBallPosition(gameBoard.size() / 2, gameBoard[0].size() / 2  );
    GameBoard::setBoardField(ball.getPosition(),(char)BoardField::BALL);
    score = make_pair(0, 0);
}

void Pong::showBoard()
{
    Pong::showScore();
    Pong::setPadle();
    GameBoard::showBoard();
}

void Pong::setPadle()
{
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

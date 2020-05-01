#include "Pong.hpp"

Pong::Pong()
{
    Padle padle;
    Ball ball;
    actualPaddlePosition = padle.setPadlePosition(gameBoard.size());
    ball.setBallPosition(gameBoard.size() / 2, gameBoard[0].size() / 2);
    GameBoard::setBoardField(ball.getBallPosition(),(char)BoardField::BALL);
    //cout << "Ball: " <<
    score = make_pair(0, 0);
}

void Pong::showBoard()
{
    Pong::showScore();
    GameBoard::showBoard();
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

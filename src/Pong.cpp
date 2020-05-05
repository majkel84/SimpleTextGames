#include "Pong.hpp"

Pong::Pong()
{
    actualPadlePosition[0] = p1.setPadlePosition(gameBoard.size() / 2);
    actualPadlePosition[1] = actualPadlePosition[0];
    ball.setBallPosition(gameBoard.size() / 2, gameBoard[0].size() / 2  );
    GameBoard::setBoardField(ball.getPosition(),(char)BoardField::BALL);
    score = make_pair(0, 0);
}

void Pong::setup()
{
    /*showBoard();
    updatePadlePosition(3,0);
    showBoard();*/
    inputEnterOff();
    while(1)
    {
        Pong::showScore();
        Pong::showBoard();
        usleep(TIME_DELAY);
        Pong::updatePadleMove(getInput(timeDelay()));
    }
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
        GameBoard::setBoardField(actualPadlePosition[0] + it, 0, (char)BoardField::PADLE);
        GameBoard::setBoardField(actualPadlePosition[1] + it, gameBoard[0].size() - 1, (char)BoardField::PADLE);
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
        updatePadlePosition(-1, 0);
        break;
    case DOWN:
        updatePadlePosition(1, 0);
        break;
    default:
        break;
    }
}

void Pong::updatePadlePosition(short y, short player)
{
        if (Pong::checkIsPadleOnBoard(y, player))
        {
            actualPadlePosition[player] += y;
            setPadle();
        }
}

bool Pong::checkIsPadleOnBoard(short move, short player)
{
        return actualPadlePosition[player] + move > 0
                ? (actualPadlePosition[player] + move + p1.getPadleSize() < gameBoard.size()
                   ? true : false)
                : false;
}

#pragma once

#include <GameBoard.hpp>
#include <GameField.hpp>
#include <GameObjects.hpp>
#include <Input.hpp>

using namespace std;

class Pong : public GameBoard
{
public:
    Pong();
    void setup();
    void showBoard();
    void clearColumn(short columnNumber);
    void setPadle();
    pair<unsigned, unsigned> getScore();
    void updateScore(unsigned player);
    void showScore();
    bool gameOver();
    void updatePadleMove(Direction direction);
    void updatePadlePosition(short y, short player);
    bool checkIsPadleOnBoard(short move, short player);

private:
    Padle p1, p2;
    Ball ball;
    unsigned short actualPadlePosition[2] = {0, 0};
    enum Direction actualBallDirection = DOWNLEFT;
    pair <unsigned, unsigned> score;
};

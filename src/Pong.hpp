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
    void updatePadleMove(Direction direction);
    void updatePadlePosition(short y);

private:
    Padle p1, p2;
    Ball ball;
    unsigned short actualPaddleOnePosition = 0;
    unsigned short actualPaddleTwoPosition = 0;
    pair <unsigned, unsigned> score;
};

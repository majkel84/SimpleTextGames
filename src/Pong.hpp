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
    void showBoard();
    pair<unsigned, unsigned> getScore();
    void updateScore(unsigned player);
    void showScore();
private:
    unsigned short actualPaddlePosition = 0;
    pair <unsigned, unsigned> score;
};

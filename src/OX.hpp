#pragma once

#include <iostream>
#include <GameField.hpp>

using namespace std;

class OX
{
public:
    OX();
    void showBoard();
    void chooseField();
    void chooseField(int row, int line);
    char getBoardField(int row, int line);
    void changePlayer();
    char getActuallPlayer();
    char checkWinner();
private:
    char gameBoard[3][3];
    char player;
    int numberOfShots = 0;
};

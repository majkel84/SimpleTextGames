#pragma once

#include <iostream>
#include <vector>
#include <GameField.hpp>

using namespace std;

class OX
{
public:
    OX();
    void showBoard();
    char getBoardField(int row, int line);
    char getActuallPlayer();
    void changePlayer();
    void chooseField();
    void chooseField(int row, int line);
    //char checkWinner();
private:
    //char gameBoard[3][3];
    vector<vector<char>> gameBoard;
    char player;
    int numberOfShots = 0;
};

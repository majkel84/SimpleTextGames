#pragma once

#include <iostream>

using namespace std;

class OX
{
public:
    void showBoard();
    void chooseField();
    void chooseField(int row, int line);
    char getBoardField(int row, int line);
private:
    char gameBoard[3][3] =
    {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
};
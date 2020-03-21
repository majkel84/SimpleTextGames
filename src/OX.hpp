#pragma once

#include <iostream>

using namespace std;

class OX
{
public:
    void showBoard();
private:
    char gameBoard[3][3] =
    {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

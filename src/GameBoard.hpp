#pragma once

#include <vector>
#include <GameField.hpp>

using namespace std;

class GameBoard
{
public:
    //GameBoard(int numberOfFields);
    char getBoardField(int row,int line);
    void showBoard();
    void chooseField();
    //~GameBoard();
protected:
    vector<vector<char>> gameBoard;
};

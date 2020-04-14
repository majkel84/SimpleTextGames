#pragma once

#include <vector>
#include <iostream>
#include <GameField.hpp>

using namespace std;

class GameBoard
{
public:
    GameBoard();
    GameBoard(int numberOfFields);
    GameBoard(int numberOfFields, char boardDefaultField);
    char getBoardField(int row,int line);
    void setBoardField(int row,int line, char field);
    void showBoard();
    void chooseField();
    //~GameBoard();
protected:
    vector<vector<char>> gameBoard;
};

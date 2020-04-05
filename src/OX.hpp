#pragma once

#include <iostream>
#include <vector>
#include <GameField.hpp>
#include <GameBoard.hpp>

using namespace std;

class OX : public GameBoard
{
public:
    OX(int numberOfFields);
    void showBoard();
    char getActuallPlayer();
    void changePlayer();
    void chooseField();
    void chooseField(int row, int line);
    void selectField(int row, int line, char field);
    char checkWinner();

private:
    char player;
    int numberOfShots = 0;
};

#pragma once

#include <iostream>
#include <ctime>

#include <GameField.hpp>

using namespace std;

class BattleShip
{
public:
    BattleShip();
    BattleShip(const unsigned short rows_lines,
               const unsigned short numberOfShips);
    void showBoard();
    void showBoard(int** b);
    void setShips(unsigned short numberOfShips);
    bool fire(int x, int y);
    int getShipsLeftOnBoard();
    ~BattleShip();

private:
    unsigned short rows_lines_;
    int** board_ = new int*[rows_lines_];
    unsigned short shipsLeftOnBoard;
    unsigned short numberOfShips_;
};

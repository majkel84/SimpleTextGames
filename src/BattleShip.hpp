#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class BattleShip
{
public:
    BattleShip(unsigned short boardSize);
    //void showBoard();
    //void setShips(unsigned short numberOfShips);
    //bool fire(int x, int y);
    //int getShipsLeftOnBoard();
    ~BattleShip();

private:
    int rows_lines_;
    int** board = new int*[rows_lines_];
    int shipsLeftOnBoard;
};

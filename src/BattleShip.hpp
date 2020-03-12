#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class BattleShip
{
public:
    BattleShip();
    int** createBoard(int boardSize);
    void showBoard();
    //void showBoard2(int** b);
    void setShips(unsigned short numberOfShips);
    bool fire(int x, int y);
    int getShipsLeftOnBoard();
    ~BattleShip();

private:
    unsigned short rows_lines_ = 5;
    int** board_ = new int*[rows_lines_];
    unsigned short shipsLeftOnBoard;
};

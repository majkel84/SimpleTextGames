#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class BattleShip
{
public:
    void createEmptyBoard(int rows_lines);
    void showBoard();
    void setShips(unsigned short numberOfShips);
    bool fire(int x, int y);
    int numberOfShipsLeft();
    ~BattleShip();

private:
    int rows_lines_;
    int** board = new int*[rows_lines_];
};

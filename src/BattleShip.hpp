#pragma once

#include <iostream>
#include <ctime>

#include <GameField.hpp>
#include <GameBoard.hpp>

using namespace std;

class BattleShip : GameBoard
{
public:
    BattleShip(int numberOfFields);
    void showBoard();
    void showBoard(int** b);
    void setShips(unsigned short numberOfShips);
    bool chooseField(int x, int y);
    int getShipsLeftOnBoard();

private:
    unsigned short shipsLeftOnBoard;
    unsigned short numberOfShips_;
};

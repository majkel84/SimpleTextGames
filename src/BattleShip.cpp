#include "BattleShip.hpp"

BattleShip::BattleShip(int numberOfFields) : GameBoard(numberOfFields)
{
    BattleShip::setShips(numberOfShips_);
}

void BattleShip::showBoard()
{
    GameBoard::showBoard();
}

void BattleShip::setShips(unsigned short numberOfShips)
{
    int ships = 0;
    shipsLeftOnBoard = numberOfShips;
    while (ships < numberOfShips)
    {
        int x = rand() % (gameBoard.size() - 1);
        int y = rand() % (gameBoard.size() - 1);
        if (gameBoard[x][y] != 1)
        {
            ships++;
            gameBoard[x][y] = 1;
        }
    }
}

bool BattleShip::chooseField(int x, int y)
{
    if (x >= gameBoard.size() || y >= gameBoard.size())
        return false;
    if (gameBoard[x][y] == 1)
    {
        gameBoard[x][y] = 2;
        shipsLeftOnBoard--;
        cout << "Got It" << endl;
        GameBoard::showBoard();
        return true;
    }
    cout << "MISS" << endl;
    return false;
}

int BattleShip::getShipsLeftOnBoard()
{
    return shipsLeftOnBoard;
}

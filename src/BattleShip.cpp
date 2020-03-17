#include "BattleShip.hpp"

BattleShip::BattleShip()
{
    for(int i = 0; i < rows_lines_; ++i)
        board_[i] = new int[rows_lines_];
}

BattleShip::BattleShip(const unsigned short rows_lines,
           const unsigned short numberOfShips)
    : rows_lines_(rows_lines),
      numberOfShips_(numberOfShips)
{
    for(int i = 0; i < rows_lines_; ++i)
        board_[i] = new int[rows_lines_];
    BattleShip::setShips(numberOfShips_);
}

void BattleShip::showBoard()
{
    if (rows_lines_ != 0)
        for (int rows = 0; rows < rows_lines_; rows++)
        {
            cout << endl;
            for (int lines = 0; lines < rows_lines_; lines++)
                cout << board_[rows][lines] << " ";
        }
}

void BattleShip::showBoard(int **b)
{
    for(int i = 0; i < rows_lines_; i++)
    {
        for (int j = 0; j <  rows_lines_; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

void BattleShip::setShips(unsigned short numberOfShips)
{
    int ships = 0;
    shipsLeftOnBoard = numberOfShips;
    while (ships < numberOfShips)
    {
        int x = rand() % (rows_lines_ - 1);
        int y = rand() % (rows_lines_ - 1);
        if (board_[x][y] != 1)
        {
            ships++;
            board_[x][y] = 1;
        }
    }
}

bool BattleShip::fire(int x, int y)
{
    if (x >= rows_lines_ || y >= rows_lines_)
        return false;
    if (board_[x][y] == 1)
    {
        board_[x][y] = 2;
        shipsLeftOnBoard--;
        cout << "Got It" << endl;
        showBoard(board_);
        return true;
    }
    cout << "MISS" << endl;
    return false;
}

int BattleShip::getShipsLeftOnBoard()
{
    return shipsLeftOnBoard;
}

BattleShip::~BattleShip()
{
    for(int i = 0; i < rows_lines_; i++)
        delete [] board_[i];
    delete [] board_;
}

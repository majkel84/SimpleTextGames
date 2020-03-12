#include "BattleShip.hpp"

BattleShip::BattleShip()
{
    for(int i = 0; i < rows_lines_; ++i)
        board_[i] = new int[rows_lines_];
}

int** BattleShip::createBoard(int boardSize)
{
    int** board = new int*[boardSize];
    for(int i = 0; i < boardSize; ++i)
        board[i] = new int[boardSize];
    return board;
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

/*void BattleShip::showBoard2(int **b)
{
    for(int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
        for (int j = 0; j <  sizeof(b)/sizeof(b[0]); j++)
            cout << b[i][j] << " ";
}*/

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
        showBoard();
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

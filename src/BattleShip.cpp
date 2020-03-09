#include <BattleShip.hpp>

void BattleShip::createEmptyBoard(int rows_lines)
{
    for(int i = 0; i < rows_lines; ++i)
        board[i] = new int[rows_lines];
    rows_lines_ = rows_lines;
}

void BattleShip::showBoard()
{
    if (rows_lines_ != 0)
        for (int rows = 0; rows < rows_lines_; rows++)
        {
            cout << endl;
            for (int lines = 0; lines < rows_lines_; lines++)
                cout << board[rows][lines] << " ";
        }
}
void BattleShip::setShips(unsigned short numberOfShips)
{
    int ships = 0;
    while (ships < numberOfShips)
    {
        int x = rand() % rows_lines_;
        int y = rand() % rows_lines_;
        if (board[x][y] != 1)
        {
            ships++;
            board[x][y] = 1;
        }
    }
}

bool BattleShip::fire(int x, int y)
{
    if (board[x][y] == 1)
    {
        board[x][y] = 2;
        return true;
    }
    cout << "MISS" << endl;
    return false;
}

//int numberOfShipsLeft();

BattleShip::~BattleShip()
{
    for(int i = 0; i < rows_lines_; ++i)
    {
        delete [] board[i];
    }
    delete [] board;
}

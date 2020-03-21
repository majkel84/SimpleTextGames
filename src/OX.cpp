#include "OX.hpp"

void OX::showBoard()
{
    for (auto rows = 0; rows < 3; rows++)
    {
        for (auto lines = 0; lines < 3; lines++)
            cout << gameBoard[rows][lines] << " ";
        cout << endl;
    }
}

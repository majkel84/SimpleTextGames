#include "OX.hpp"

OX::OX()
{
    player = (char)BoardField::X;
    for (auto rows = 0; rows < 3; rows++)
        for (auto lines = 0; lines < 3; lines++)
            gameBoard[rows][lines] = (char)BoardField::UNKNOWN;
}

void OX::showBoard()
{
    for (auto rows = 0; rows < 3; rows++)
    {
        for (auto lines = 0; lines < 3; lines++)
            cout << gameBoard[rows][lines] << " ";
        cout << endl;
    }
}

char OX::getBoardField(int row, int line)
{
    return gameBoard[row][line];
}

void OX::chooseField()
{
    int row, line;
    cout << "Choose Your field (1st - row): ";
    cin >> row;
    cout << "2nd - line: ";
    cin >> line;
    gameBoard[row][line] = player;
    numberOfShots++;
    if (numberOfShots >=5)
        checkWinner();
    OX::changePlayer();
}

void OX::chooseField(int row, int line)
{
    gameBoard[row][line] = player;
    numberOfShots++;
    if (numberOfShots >=5)
        checkWinner();
    OX::changePlayer();
}

void OX::changePlayer()
{
    if (player == 'X')
        player = (char)BoardField::O;
    else if (player == 'O')
        player = (char)BoardField::X;
}

char OX::getActuallPlayer()
{
    return player;
}

char OX::checkWinner()
{
    // any of the rows is same
    for (int i=0; i<=2; i++)
        if(gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][1]==gameBoard[i][2] && gameBoard[i][0]!=0)
            return gameBoard[i][0];
    // any of the columns is same
    for(int i=0; i<=2; i++)
        if (gameBoard[0][i]==gameBoard[1][i] && gameBoard[1][i]==gameBoard[2][i] && gameBoard[0][i]!=0)
            return gameBoard[0][i];

    // 1st diagonal is same
    if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2] && gameBoard[0][0]!=0)
        return gameBoard[0][0];;

    // 2nd diagonal is same
    if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][0] && gameBoard [0][2]!=0)
         return gameBoard[0][2];
    return (char)BoardField::UNKNOWN;
}

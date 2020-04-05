#include "OX.hpp"

OX::OX(int numberOfFields) : GameBoard(numberOfFields)
{
    for (auto rows = 0; rows < numberOfFields; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < numberOfFields; lines++)
            row.push_back((char)BoardField::UNKNOWN);
        gameBoard.push_back(row);
    }
    player = (char)BoardField::X;
}

void OX::showBoard()
{
    GameBoard::showBoard();
}

char OX::getActuallPlayer()
{
    return player;
}

char OX::getBoardField(int row, int line)
{
    return gameBoard[row][line];
}

void OX::changePlayer()
{
    if (player == 'X')
        player = (char)BoardField::O;
    else if (player == 'O')
        player = (char)BoardField::X;
}

void OX::chooseField()
{
    int row, line;
    cout << "Choose Your field (1st - row): ";
    cin >> row;
    cout << "2nd - line: ";
    cin >> line;
    OX::chooseField(row, line);
}

void OX::chooseField(int row, int line)
{
    try
    {
        if (row > 2)
            throw row;
        if (line > 2)
            throw line;
        OX::selectField(row, line, player);
    } catch (int e)
    {
        cout << "Value " << e << " higher than game board size";
    }
}

void OX::selectField(int row, int line, char field)
{
    while (gameBoard[row][line] == '*' && numberOfShots < 9)
    {
        gameBoard[row][line] =field;
        numberOfShots++;
        if (numberOfShots >=5)
            if (checkWinner())
                cout << "Player " << player << " won" << endl;
        OX::changePlayer();
    }
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
    return 0;
}

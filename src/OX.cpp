#include "OX.hpp"

OX::OX()
{
    player = (char)BoardField::X;
    for (auto rows = 0; rows < 3; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < 3; lines++)
            row.push_back((char)BoardField::UNKNOWN);
        gameBoard.push_back(row);
    }
}

void OX::showBoard()
{
    for (auto& row: gameBoard)
    {
        for (auto& column: row)
            cout << column << " ";
    cout << endl;
    }
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
    try
    {
        if (row > 2)
            throw row;
        if (line > 2)
            throw line;
        gameBoard[row][line] = player;
        numberOfShots++;
        if (numberOfShots >=5)
            if (checkWinner())
                cout << "Player " << checkWinner() << " won" << endl;
        OX::changePlayer();
    } catch (int e)
    {
        cout << "Value " << e << " higher than game board size";
    }
}

void OX::chooseField(int row, int line)
{
    try
    {
        if (row > 2)
            throw row;
        if (line > 2)
            throw line;
        gameBoard[row][line] = player;
        numberOfShots++;
        if (numberOfShots >=5)
            if (checkWinner())
                cout << "Player " << player << " won" << endl;
        OX::changePlayer();
    } catch (int e)
    {
        cout << "Value " << e << " higher than game board size";
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

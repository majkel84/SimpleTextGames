#include "GameBoard.hpp"

GameBoard::GameBoard(int numberOfFields)
{
    for (auto rows = 0; rows < numberOfFields; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < numberOfFields; lines++)
            row.push_back((char)BoardField::UNKNOWN);
        gameBoard.push_back(row);
    }
}

GameBoard::GameBoard(int numberOfFields, char boardDefaultField)
{
    for (auto rows = 0; rows < numberOfFields; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < numberOfFields; lines++)
            row.push_back(boardDefaultField);
        gameBoard.push_back(row);
    }
}

char GameBoard::getBoardField(int row,int line)
{
    return gameBoard[row][line];
}

void GameBoard::showBoard()
{
    for (auto& row: gameBoard)
    {
        for (auto& column: row)
            cout << column << " ";
    cout << endl;
    }
}

void GameBoard::chooseField()
{

}

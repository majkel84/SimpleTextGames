#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    GameBoard::fillGameBoardLine(20, (char)BoardField::WALL);
    for (auto rows = 1; rows < 10; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < 20; lines++)
            row.push_back((char)BoardField::SNAKEBOARD);
        gameBoard.push_back(row);
    }
    GameBoard::fillGameBoardLine(20, (char)BoardField::WALL);
}

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

void GameBoard::setBoardField(int row, int line, char field)
{
    gameBoard[row][line] = field;
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

void GameBoard::fillGameBoardLine(int numberOfChars, char value)
{
    vector <char> row (numberOfChars, value);
    gameBoard.push_back(row);
}

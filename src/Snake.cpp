#include <Snake.hpp>

Snake::Snake(int numberOfFields, char boardDefaultField) : GameBoard(numberOfFields, boardDefaultField)
{
    Snake::setStartPosition();
    Snake::putFruitOnBoard();
}

void Snake::setup()
{
    while(!gameOver)
    {
        Snake::drawBoard();
    }
}

void Snake::setStartPosition()
{
    snakePosition.first = boardSize / 2;
    snakePosition.second = boardSize / 2;
}

void Snake::putFruitOnBoard()
{
        fruitPosition.first = rand() % boardSize;
        fruitPosition.second = rand() % boardSize;
        if (gameBoard[fruitPosition.first][fruitPosition.second] != (char)BoardField::SNAKEBOARD)
            Snake::putFruitOnBoard();
}

void Snake::drawBoard()
{
    Snake::clearBoard();
    GameBoard::showBoard();
}

void Snake::clearBoard()
{
    vector<char> row;
    cout << "\033[2J\033[1;1H";
    for (auto rows = 0; rows < boardSize; rows++)
    {
        row.clear();
        for (auto lines = 0; lines < boardSize; lines++)
            row.push_back((char)BoardField::SNAKEBOARD);
        //gameBoard.push_back(row);
    }

}




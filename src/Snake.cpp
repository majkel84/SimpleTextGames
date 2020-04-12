#include <Snake.hpp>

Snake::Snake() : GameBoard()
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
    snakePosition.first = width / 2;
    snakePosition.second = height / 2;
}

void Snake::putFruitOnBoard()
{
        fruitPosition.first = rand() % width;
        fruitPosition.second = rand() % height;
        if (fruitPosition.first == snakePosition.first && fruitPosition.second == snakePosition.second)
            Snake::putFruitOnBoard();
}

void Snake::drawBoard()
{
    Snake::clearBoard();
    Snake::showBoard();
}

void Snake::clearBoard()
{
    cout << "\033[2J\033[1;1H";
    for (auto rows = 0; rows < width; rows++)
    {
        vector<char> row;
        for (auto lines = 0; lines < height; lines++)
            row.push_back((char)BoardField::SNAKEBOARD);
        gameBoard.push_back(row);
    }

}




#include <Snake.hpp>

void Snake::setup()
{
    Snake::setStartPosition();
    Snake::putFruitOnBoard();
    while(!gameOver)
    {
        Snake::input();
        Snake::show();
        Snake::logic();
    }
}

void Snake::setStartPosition()
{
    snakeX = width / 2;
    snakeY = height / 2;
}

void Snake::putFruitOnBoard()
{
        fruitX = rand() % width;
        fruitY = rand() % height;
        if (fruitX == snakeX && fruitY == snakeY)
            Snake::putFruitOnBoard();
}

void Snake::input()
{

}

void Snake::show()
{
    cout << "\033[2J\033[1;1H";
}

void Snake::logic()
{

}




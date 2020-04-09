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
    Snake::drawHorizontalBorder();
    Snake::drawVerticalBorder();
    Snake::drawHorizontalBorder();
}

void Snake::drawHorizontalBorder()
{
    for (auto i = 0; i < width; i++)
        cout << (char)BoardField::WALL;
    cout << endl;
}

void Snake::drawVerticalBorder()
{
    for (auto h = 0; h < height - 1; h++)
    {
        for (auto w = 0; w < width; w++)
        {
            if (w == 0 || w == width - 1)
                cout << (char)BoardField::WALL;
            else
                cout << (char)BoardField::BLANK;
        }
        cout << endl;
    }

}

void Snake::logic()
{

}




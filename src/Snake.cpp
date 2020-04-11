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
    for (auto i = 0; i < width + 1; i++)
        cout << (char)BoardField::WALL;
    cout << endl;
}

void Snake::drawVerticalBorder()
{
    for (auto h = 0; h < height - 1; h++)
    {
        for (auto w = 0; w < width + 1; w++)
        {
            if (w == 0 || w == width)
                cout << (char)BoardField::WALL;
            else if (h == snakeX && w == snakeY)
                cout << (char)BoardField::SNAKEHEAD;
            else if (h == fruitX && w == fruitY)
                cout << (char)BoardField::UNKNOWN;
            else
                cout << (char)BoardField::BLANK;
        }
        cout << endl;
    }

}

void Snake::logic()
{

}




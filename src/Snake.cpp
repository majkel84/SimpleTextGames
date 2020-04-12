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
            else if (h == snakePosition.first && w == snakePosition.second)
                cout << (char)BoardField::SNAKEHEAD;
            else if (h == fruitPosition.first && w == fruitPosition.second)
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




#include <Snake.hpp>

Snake::Snake(int numberOfFields, char boardDefaultField) : GameBoard(numberOfFields, boardDefaultField)
{
    boardSize = numberOfFields;
    srand(time(NULL));
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
    snake.push_back(make_pair(boardSize / 2, boardSize / 2));
    GameBoard::setBoardField(snake[0].first, snake[0].second, (char)BoardField::SNAKEHEADRIGHT);
    if (boardSize / 2 >= INITIAL_SNAKE_LENGTH - 1)
    {
       for (auto snakeParts = 1; snakeParts < INITIAL_SNAKE_LENGTH; snakeParts++)
       {
           snake.push_back(make_pair(snake[0].first, snake[0].second - snakeParts));
           GameBoard::setBoardField(snake[snakeParts].first, snake[snakeParts].second, (char)BoardField::SNAKEBODY);
       }
    }
    else
        cout << "Snake too long to start" << endl;
}

void Snake::putFruitOnBoard()
{
    if (snakeFoodEaten)
    {
        while (true) {
            fruitPosition.first = rand() % boardSize;
            fruitPosition.second = rand() % boardSize;
            if (gameBoard[fruitPosition.first][fruitPosition.second] == (char)BoardField::SNAKEBOARD)
            {
                GameBoard::setBoardField(fruitPosition.first, fruitPosition.second, (char)BoardField::UNKNOWN);
                snakeFoodEaten = false;
                break;
            }
        }
    }
}

void Snake::drawBoard()
{
    Snake::clearBoard();
    gameBoard[fruitPosition.first][fruitPosition.second] = (char)BoardField::UNKNOWN;
    gameBoard[snake[0].first][snake[0].second] = actualSNakeHeadDirection;
    for (auto it = 1; it < snake.size(); it++)
        gameBoard[snake[it].first][snake[it].second] = (char)BoardField::SNAKEBODY;
    GameBoard::showBoard();
}

void Snake::clearBoard()
{
    gameBoard.clear();
    vector<char> row;
    cout << "\033[2J\033[1;1H";
    for (auto rows = 0; rows < boardSize; rows++)
    {
        row.clear();
        for (auto lines = 0; lines < boardSize; lines++)
            row.push_back((char)BoardField::SNAKEBOARD);
        gameBoard.push_back(row);
    }
}

int Snake::getScore()
{
    return snakeLength;
}

enum Direction Snake::getDirection()
{
    enum Direction result = RIGHT;
    sem_wait(&this->snake_sema);
    result = this->direction;
    sem_post(&this->snake_sema);
    return result;
}

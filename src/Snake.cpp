#include <Snake.hpp>
#include <time.h>

Snake::Snake(int numberOfFields, char boardDefaultField) : GameBoard(numberOfFields, boardDefaultField)
{
    boardSize = numberOfFields;
    srand(time(NULL));
    Snake::setStartPosition();
    Snake::putFruitOnBoard();
}

void Snake::setup()
{
    initialize();
    while(!gameOver)
    {
        Snake::drawBoard();
        cout << endl << "Actual score: " << Snake::getScore() << endl;
        usleep(TIME_DELAY);

        fd_set fdset;
        struct timeval timeout;
        int  rc;
        timeout.tv_sec = 0,5;   /* wait for 6 seconds for data */
        timeout.tv_usec = 0;
        FD_ZERO(&fdset);
        FD_SET(0, &fdset);
        rc = select(1, &fdset, NULL, NULL, &timeout);
        if (rc == 0) {} /* select timed out */
        else
        {
           if (FD_ISSET(0, &fdset))
           {
              Snake::updateDirection(getInput(getchar()));
           }
        }
        Snake::updateSnakeMove();
        if (snakeFoodEaten)
            Snake::putFruitOnBoard();
        Snake::isGameOver();
    }
    Snake::snakeGameOver();
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
    {
        cout << "Snake too long to start" << endl;
        gameOver = true;
    }
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

void Snake::snakeGameOver()
{
    cout << "GAME OVER" << endl;
    cout << "Your score was " << Snake::getScore() << endl;
}

enum Direction Snake::getDirection()
{
    return direction;
}

void Snake::updateDirection(Direction direct)
{
    direction = Snake::validateDirection(direct);
}

enum Direction Snake::validateDirection(Direction direction)
{
    switch (direction)
    {
    case RIGHT:
        if (this->direction != LEFT)
        {
            this->direction = direction;
        }
        break;
    case UP:
        if (this->direction != DOWN)
        {
            this->direction = direction;
        }
        break;
    case LEFT:
        if (this->direction != RIGHT)
        {
            this->direction = direction;
        }
        break;
    case DOWN:
        if (this->direction != UP)
        {
            this->direction = direction;
        }
        break;
    }
    return direction;
}

void Snake::updateSnakeHeadDirection()
{
    enum Direction direct = Snake::getDirection();
    switch (direct)
    {
    case LEFT:
        actualSNakeHeadDirection = (char)BoardField::SNAKEHEADLEFT;
        break;
    case RIGHT:
        actualSNakeHeadDirection = (char)BoardField::SNAKEHEADRIGHT;
        break;
    case UP:
        actualSNakeHeadDirection = (char)BoardField::SNAKEHEADUP;
        break;
    case DOWN:
        actualSNakeHeadDirection = (char)BoardField::SNAKEHEADDOWN;
        break;
    default:
        break;
    }
    gameBoard[snake[0].first][snake[0].second] = actualSNakeHeadDirection;
}

void Snake::updateSnakeMove()
{
    enum Direction direct = getDirection();
    switch (direct)
    {
    case RIGHT:
        Snake::updateSnakeHeadDirection();
        Snake::updateSnakePosition(0, 1);
        break;
    case LEFT:
        Snake::updateSnakeHeadDirection();
        Snake::updateSnakePosition(0, -1);
        break;
    case UP:
        Snake::updateSnakeHeadDirection();
        Snake::updateSnakePosition(-1, 0);
        break;
    case DOWN:
        Snake::updateSnakeHeadDirection();
        Snake::updateSnakePosition(1, 0);
        break;

    }
}

void Snake::updateSnakePosition(short x, short y)
{
    if (snake[0].first + x == fruitPosition.first && snake[0].second + y == fruitPosition.second)
    {
        snakeFoodEaten = true;
        snakeLength++;
        pair <int, int> snakeNewPosition = make_pair(snake[0].first + x, snake[0].second + y);
        vector <pair<int, int>>::iterator it = snake.begin();
        snake.insert(it, snakeNewPosition);
    }
    else
    {
        for (auto i = snake.size(); i > 0; i--)
        {
            snake[i].first = snake[i-1].first;
            snake[i].second = snake[i-1].second;
        }
        snake[0].first += x;
        snake[0].second += y;
    }
}

void Snake::isGameOver()
{
    if (Snake::checkIfSnakeIsOnBoard() || Snake::cheskIfSnakeIsHit())
        gameOver = true;
}

bool Snake::checkIfSnakeIsOnBoard()
{
    return
            snake[0].first < 0 ||
            snake[0].first > boardSize ||
            snake[0].second < 0 ||
            snake[0].second > boardSize
            ? true : false;
}

bool Snake::cheskIfSnakeIsHit()
{
    for (auto i = 1; i < snake.size(); i++)
        if (snake[0].first == snake[i].first && snake[0].second == snake[i].second)
            return true;
    return false;
}

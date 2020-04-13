#include <Input.hpp>

struct termios t;

void inputEnterOff()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void inputEnterOn()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

enum Direction getInput()
{
    {
        enum Direction result = RIGHT;
        char user_input = getchar();
        switch (user_input)
        {
        case 'a':
            result = LEFT;
            break;
        case 'w':
            result = UP;
            break;
        case 'd':
            result = RIGHT;
            break;
        case 's':
            result = DOWN;
            break;
        default:
            result = ERROR;
            cout << "Incorrect button clicked(" << user_input << ")" << endl;
            break;
        }
        return result;
    }
}

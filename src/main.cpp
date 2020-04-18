#include "BattleShip.hpp"
#include "OX.hpp"
#include "Snake.hpp"

int main()
{
    Snake s(5, '.');
    cout << "FIRST" << endl;
    s.drawBoard();
    s.updateSnakeMove();
    cout << "RIGHT" << endl;
    s.drawBoard();

    return 0;
}

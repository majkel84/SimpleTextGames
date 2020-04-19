#include "BattleShip.hpp"
#include "OX.hpp"
#include "Snake.hpp"

int main()
{
    Snake s(5, '.');
    cout << "FIRST" << endl;
    s.drawBoard();
    s.updateDirection(UP);
    s.updateSnakeMove();
    cout << "UP" << endl;
    s.drawBoard();
    //s.setup();

    return 0;
}

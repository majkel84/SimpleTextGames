#include "BattleShip.hpp"
#include "OX.hpp"
#include "Snake.hpp"
#include "Pong.hpp"

int main()
{
    Snake s(10, '.');
    cout << "FIRST" << endl;
    s.drawBoard();
    s.updateDirection(UP);
    s.updateSnakeMove();
    cout << "UP" << endl;
    s.drawBoard();
    //s.setup();

    //Pong p;
    //p.setup();
    return 0;
}

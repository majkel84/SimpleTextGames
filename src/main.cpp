#include "BattleShip.hpp"
#include "OX.hpp"
#include "Snake.hpp"

int main()
{
    Snake s(5, '.');
    s.clearBoard();
    s.putFruitOnBoard();
    //s.setStartPosition();
    s.drawBoard();

    return 0;
}

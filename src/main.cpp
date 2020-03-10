#include "BattleShip.hpp"

int main()
{
    BattleShip bs;
    bs.setShips(5);
    bs.showBoard();
    bs.fire(1,2);
    bs.fire(5,2);
    bs.fire(2,3);

    return 0;
}

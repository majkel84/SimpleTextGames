#include "BattleShip.hpp"

int main()
{
    BattleShip bs(5, 5);
    bs.fire(1,2);
    bs.fire(5,2);
    bs.fire(2,3);
    bs.~BattleShip();

    return 0;
}

#include "BattleShip.hpp"

int main()
{
    BattleShip bs;
    bs.showBoard(bs.createBoard(5));
    bs.setShips(5);
    bs.fire(1,2);
    bs.fire(5,2);
    bs.fire(2,3);

    return 0;
}

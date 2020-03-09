#include <iostream>
#include "BattleShip.hpp"

using namespace std;

int main()
{
    BattleShip bs;
    bs.createEmptyBoard(5);
    bs.setShips(5);
    bs.fire(1,2);

    return 0;
}

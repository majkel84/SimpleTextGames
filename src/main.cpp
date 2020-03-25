#include "BattleShip.hpp"
#include "OX.hpp"

int main()
{
    OX ox;
    ox.initializeBoard();
    ox.chooseField(0,0);
    ox.chooseField(1,1);
    ox.showBoard();

    return 0;
}

#include "BattleShip.hpp"
#include "OX.hpp"

int main()
{
    OX ox(3);
    ox.chooseField(0,0);
    ox.chooseField(1,1);
    //ox.chooseField(1,1);
    ox.chooseField(0,1);
    ox.chooseField(1,0);
    ox.chooseField(2,2);
    ox.chooseField(1,2);
    ox.showBoard();

    return 0;
}

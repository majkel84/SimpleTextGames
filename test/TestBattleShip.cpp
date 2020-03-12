#include <gtest/gtest.h>
#include "BattleShip.hpp"

struct TestBattleShip : public ::testing::Test
{
    BattleShip bs;
};

TEST_F(TestBattleShip, checkWrongShot)
{
    bs.setShips(5);
    ASSERT_FALSE(bs.fire(0,0));
}

TEST_F(TestBattleShip, checkShipsLeft)
{
    bs.setShips(5);
    ASSERT_EQ(bs.getShipsLeftOnBoard(),5);
}



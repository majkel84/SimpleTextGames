#include <gtest/gtest.h>
#include "BattleShip.hpp"

struct TestBattleShip : public ::testing::Test
{
    BattleShip bs;
};

TEST_F(TestBattleShip, checkWronFire)
{
    bs.setShips(5);
    ASSERT_FALSE(bs.fire(0,0));
}



#include <gtest/gtest.h>
#include "BattleShip.hpp"

struct TestArrays : public ::testing::Test
{
    BattleShip bs;
};

TEST_F(TestArrays, checkRotationByThree)
{
    bs.setShips(5);
    ASSERT_FALSE(bs.fire(0,0));
}



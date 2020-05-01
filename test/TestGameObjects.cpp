#include <gtest/gtest.h>
#include "GameObjects.hpp"

struct TestGameObjects : public ::testing::Test
{
    GameObjects gameObject;
    Ball ball;
};

TEST_F(TestGameObjects, checkBallPosition)
{
    ball.setBallPosition(1,1);
    pair<unsigned, unsigned> b = ball.getBallPosition();
    ASSERT_EQ(b.first, 1);
    ASSERT_EQ(b.second, 1);
}

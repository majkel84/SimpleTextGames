#include <gtest/gtest.h>
#include "Pong.hpp"

struct TestPong : public ::testing::Test
{
    Pong p;
};

TEST_F(TestPong, testBallSet)
{
    p.setBallOnBoard(1, 1);
    pair<unsigned, unsigned> ball = p.getBallPosition();
    ASSERT_EQ(ball.first, 1);
    ASSERT_EQ(ball.second, 1);
}

TEST_F(TestPong, testScoreSet)
{
    p.updateScore(2);
    pair<unsigned, unsigned> score = p.getScore();
    ASSERT_EQ(score.first, 0);
    ASSERT_EQ(score.second, 1);
}

#include <gtest/gtest.h>
#include <string>
#include "OX.hpp"

struct TestOX : public ::testing::Test
{
    OX ox;
};

TEST_F(TestOX, checkSetField)
{
    ox.chooseField(1,1);
    ox.chooseField(1,1);
    char testValue = ox.getBoardField(1,1);
    EXPECT_EQ((char)testValue, 88);
}

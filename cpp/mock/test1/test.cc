#include "helloworld.h"
#include "mockmessenger.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <string>

using namespace testing;

TEST(HelloWorldTest, getMessagetest)
{
    MockMessenger messenger;
    std::string msg = "helloworld";
    EXPECT_CALL(messenger, getMessage()).WillRepeatedly(Return(ByRef(msg)));

    HelloWorld helloworld;
    EXPECT_EQ("helloworld", helloworld.getMessage(&messenger));
    EXPECT_EQ("helloworld", helloworld.getMessage(&messenger));
    EXPECT_EQ("helloworld", helloworld.getMessage(&messenger));
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

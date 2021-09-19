#include <gtest/gtest.h>
#include <iostream>
#include <stdlib.h>

void Foo(void)
{
    int* pInt = 0;
    *pInt = 42;
}

TEST(FooDeathTest, Demo)
{
   // ASSERT_DEATH(Foo(), "");
   EXPECT_EXIT(_exit(1),testing::ExitedWithCode(1),"error");
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

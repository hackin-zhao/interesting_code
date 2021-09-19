#include <gtest/gtest.h>
#include <iostream>

class Box
{
  public:
    Box()
        : length(1.0), breadth(1.0), height(1.0)
    {
    }

    double getVolume(void)
    {
        return length * breadth * height;
    }

    double setLength(double len)
    {
        length = len;
    }

    double setBreadth(double bre)
    {
        breadth = bre;
    }

    double setHeight(double hei)
    {
        height = hei;
    }

    Box operator+(const Box &b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

    bool operator==(const Box &a)
    {
        if (this->breadth == a.breadth && this->height == a.height && this->length == a.length)
            return true;
        else
            return false;
    }

  private:
    double length;
    double breadth;
    double height;
};

TEST(CppOperatorTest, add)
{
    Box box1, box2, box3;
    box3.setBreadth(2.0);
    box3.setHeight(2.0);
    box3.setLength(2.0);
    EXPECT_EQ(true, (box1 + box2) == box3);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

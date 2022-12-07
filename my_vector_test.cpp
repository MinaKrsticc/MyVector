#include<gtest/gtest.h>
#include "../src/MyString/my_vector.h"

using namespace my_vector;

TEST(MyVectorTest, TestSizeOfVector)
{
    int elem = 6;
    MyVector vec(elem);
    EXPECT_EQ(1, vec.size());
}

TEST(MyVectorTest, TestIsEmptyWhenIsNotEmpty)
{
    int elem = 3;
    MyVector vec(elem);
    EXPECT_FALSE(vec.is_empty());
}

TEST(MyVectorTest, TestIsEmptyWhenIstEmpty)
{
    MyVector vec{};
    EXPECT_TRUE(vec.is_empty());
}

TEST(MyVectorTest, TestPushFrontWhenIsVectorEmpty)
{
    MyVector vec{};
    vec.push_front(4);
    EXPECT_EQ(1, vec.size());
    EXPECT_TRUE((vec[0] == 4));
}

TEST(MyVectorTest, TestPushBackWhenIsNotEmpty)
{
    MyVector vec(6);
    vec.push_back(4);
    EXPECT_EQ(2, vec.size());
    EXPECT_TRUE((vec[1] == 4));
}

TEST(MyVectorTest, TestApendAt)
{
    MyVector vec(4);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);

    vec.appand_at(5, 2);
    EXPECT_EQ(5, vec.size());
    EXPECT_TRUE(vec[2] == 5);
}

TEST(MyVectorTest, TestPopBack)
{
    MyVector vec(5);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(8);
    int pom = vec.pop_back();
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(pom, 8);
}

TEST(MyVectorTest, TestPopFront)
{
    MyVector vec(5);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(8);
    int pom = vec.pop_front();
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(pom, 5);
}

TEST(MyVectorTest, TestRemoveAt)
{
    MyVector vec(5);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(8);
    int pom = vec.remove_at(1);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(pom, 4);
}

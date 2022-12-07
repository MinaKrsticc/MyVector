#include<gtest/gtest.h>
#include "../src/MyString/my_array.h"

using namespace my_array;

TEST(MyArrayTest, TestSizeOfArray)
{
    int arrayInteger[] = {9, 8, 9, 8, 8};
    MyArray array(arrayInteger, 5);
    EXPECT_EQ(5, array.size());
}

TEST(MyArrayTest, TestIsEmptyWhenIsNotEmpty)
{
    int arrayInteger[] = {9, 8, 9, 8, 8};
    MyArray array(arrayInteger, 5);

    EXPECT_FALSE(array.is_empty());
}

TEST(MyArrayTest, TestIsEmptyWhenIstEmpty)
{
    MyArray array{};

    EXPECT_TRUE(array.is_empty());
}

TEST(MyArrayTest, TestPushFrontWhenIsArrayEmpty)
{
    MyArray array{};
    array.push_front(4);
    EXPECT_EQ(1, array.size());
    EXPECT_TRUE((array[0] == 4));
}

TEST(MyArrayTest, TestPushBackWhenArrayIsNotEmpty)
{
    int arrayInteger[] = {9, 8, 9, 8, 8};
    MyArray array(arrayInteger, 5);
    array.push_back(5);
    EXPECT_EQ(6, array.size());
    EXPECT_TRUE(array[5] == 5);
}

TEST(MyArrayTest, TestApendAt)
{
    int arrayInteger[] = {9, 8, 9, 8, 8};
    MyArray array(arrayInteger, 5);
    array.appand_at(5, 3);
    EXPECT_EQ(6, array.size());
    EXPECT_TRUE(array[3] == 5);
}

TEST(MyArrayTest, TestPopBack)
{
    int arrayInteger[] = {1, 1, 1, 1, 8};
    MyArray array(arrayInteger, 5);
    int pom = array.pop_back();
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(pom, 8);
}

TEST(MyArrayTest, TestPopFront)
{
    int arrayInteger[] = {8, 1, 1, 1, 1};
    MyArray array(arrayInteger, 5);
    int pom = array.pop_front();
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(pom, 8);
}

TEST(MyArrayTest, TestRemoveAt)
{
    int arrayInteger[] = {1, 1, 8, 1, 1};
    MyArray array(arrayInteger, 5);
    int pom = array.remove_at(2);
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(pom, 8);
}
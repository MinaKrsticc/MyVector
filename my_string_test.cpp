#include<gtest/gtest.h>
#include "../src/MyString/my_string.h"

using namespace my_string;

TEST(TestLen, OutputTest)
{
MyString a("mina");
EXPECT_EQ(4, a.len());
}

TEST(TestCat, OutputTest)
{
MyString a("mina");
char b[] = "mince";
a.cat(b);
MyString res("minamince");
EXPECT_TRUE(res == a);
}

TEST(TestSubstring, OutputTest)
{
MyString a("karamela");
MyString b("am");
MyString c{a.substring(3,2)};
EXPECT_TRUE(c == b);
}

TEST(TestAppend, OutputTest)
{
char str[] = {"moljac"};
MyString a("karavan");
MyString b("kamoljacravan");
MyString c = a.append(2, str);
EXPECT_TRUE(c == b);
}

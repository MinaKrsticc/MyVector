#pragma once
#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <exception>
#include "Iterator.h"

using namespace std;

namespace my_string {

class MyString{
private:
    char *stringValue;

    int stringcmp(char* a, char*b);
    friend class MyStringIterator;

public:

    MyString();
    MyString(int len);
    MyString(const MyString&);//konstruktor kopije
    MyString(const char* newString);
    ~MyString();//destruktor

    int length(MyString& rhs);
    int len();
    void cat(char* newString);
    bool isSubstring(char* substr);
    MyString substring(int pos, int length);

    MyString append(int pos, char* str);
    MyString append1(int pos, char* str);


    friend istream& operator>>(istream& in, const MyString& str);
    friend ostream& operator<<(ostream& out, const MyString& str);
    bool operator==(const MyString& rhs);
    MyString operator+(const MyString& rhs);
    MyString operator=(const MyString& rhs);

    MyStringIterator begin()
    {
        MyStringIterator it(&this->stringValue[0]);
        return it;
    }

    MyStringIterator end()
    {
        int len = this->len();
        MyStringIterator it(&this->stringValue[len - 1]);
        return it;
    }

};

}

#endif // MY_STRING_H


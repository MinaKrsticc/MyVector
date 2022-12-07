#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace my_array {

class MyArray{

private:
    int *data;
    int sizeData;
    int freeMemorySize;

public:

    MyArray();
    MyArray(const MyArray& copy);//konstruktor kopije
    MyArray(const int* newInt, int sizeNewInt);

    ~MyArray();
    int size();
    bool is_empty();
    void push_front(int elem);
    void push_back(int elem);
    void appand_at(int elem, int index);
    int pop_front();
    int pop_back();
    int remove_at(int index);

    bool operator==(const MyArray& rhs);
    bool operator!=(const MyArray& rhs);
    int& operator[](int index);

    MyArray operator=(const MyArray& rhs);
    friend ostream& operator<<(ostream& out, const MyArray& arr);
};

}
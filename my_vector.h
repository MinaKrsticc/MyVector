#pragma once
#include <vector>
#include <iostream>
#include <exception>

using namespace std;

namespace my_vector
{
    struct Node
    {
        int data; //vrednost
        Node *next; //pokazivac koji pokazuje dokle smo stigli 
    };

    class MyVector
    {
    public:
    
        MyVector();
        MyVector(int elem);
        MyVector(const MyVector &copy); // konstruktor kopije

        ~MyVector();
        int size();
        bool is_empty();
        void push_front(int elem);
        void push_back(int elem);
        void appand_at(int elem, int index);
        int pop_front();
        int pop_back();
        int remove_at(int index);

        bool operator==(const MyVector &rhs);
        bool operator!=(const MyVector &rhs);
        MyVector operator=(const MyVector &rhs);

        int& operator[](int index);

        friend ostream &operator<<(ostream &out, const MyVector &arr);

    private:
        Node *Head;//pokazivac koji pokazuje samo na prvi

    };
}
#include <vector>
#include <iostream>
#include <string.h>
#include "exception.h"
#include "my_array.h"

using namespace std;

namespace my_array
{
    int const n = 10;

    MyArray::MyArray()
    {
        this->sizeData = 0;
        this->freeMemorySize = 0;
        // this->data = new int[this->sizeData];
        this->data = nullptr;
    }

    MyArray::MyArray(const MyArray &copy)
    {
        if (copy.data == nullptr)
        {
            throw ArrayIsEmptyException();
        }
        this->freeMemorySize = copy.freeMemorySize;
        this->sizeData = copy.sizeData;
        this->data = new int[copy.sizeData];
        for (int i = 0; i < copy.sizeData; i++)
        {
            this->data[i] = copy.data[i];
        }
    }

    MyArray::MyArray(const int *newArray, int sizeNewArray)
    {
        if (sizeNewArray < 0 || newArray == nullptr)
        {
            throw InvalidArgumentException();
        }
        this->freeMemorySize = 0;
        this->sizeData = sizeNewArray;
        this->data = new int[sizeNewArray];
        for (int i = 0; i < sizeNewArray; i++)
        {
            this->data[i] = newArray[i];
        }
    }

    MyArray MyArray::operator=(const MyArray &rhs)
    {
        if (rhs.data == nullptr || rhs.sizeData == 0)
        {
            throw ArrayIsEmptyException();
        }

        delete[] this->data;
        int len = rhs.sizeData;
        this->data = new int[len];
        for (int i = 0; i < len; i++)
        {
            this->data[i] = rhs.data[i];
        }
        this->sizeData = rhs.sizeData;
        this->freeMemorySize = rhs.freeMemorySize;
        return *this;
    }

    MyArray::~MyArray()
    {
        if (this->data != nullptr)
        {
            delete this->data;
            this->data = nullptr;
            this->sizeData = 0;
        }
    }

    ostream &operator<<(ostream &out, const MyArray &arr)
    {
        for (int i = 0; i < arr.sizeData; i++)
        {
            out << arr.data[i] << endl;
        }
        return out;
    }

    bool MyArray::operator==(const MyArray &rhs)
    {
        if (rhs.data == nullptr || rhs.sizeData == 0 || this->data == nullptr || this->sizeData == 0)
        {
            throw ArrayIsEmptyException();
        }

        int lenRhs = rhs.sizeData;
        int len = this->sizeData;
        bool isEqual = false;
        int i = 0;
        if (len == 0 && lenRhs == 0)
        {
            isEqual == true;
        }
        else if (len != 0 && lenRhs != 0 && len == lenRhs)
        {
            while (i <= len && rhs.data[i] == this->data[i])
            {
                i++;
            }

            if (i == len)
            {
                isEqual = true;
            }
        }
        return isEqual;
    }

    int &MyArray::operator[](int index)
    {
        if (index < 0 || index >= this->sizeData)
        {
            throw InvalidArgumentException();
        }
        else
        {
            return this->data[index];
        }
    }

    int MyArray::size()
    {
        int sizeData = this->sizeData;
        return sizeData;
    }

    bool MyArray::is_empty()
    {
        bool isEmpty = false;
        if (this->data == nullptr)
        {
            isEmpty = true;
        }
        return isEmpty;
    }

    bool MyArray::operator!=(const MyArray &rhs)
    {
        return !(*this == rhs);
    }

    void MyArray::push_front(int elem)
    {
        if (this->freeMemorySize <= 0)
        {
            this->freeMemorySize = this->freeMemorySize + n;
        }
        int i = 0;
        int sizeNew = this->sizeData + 1;
        int *newData = new int[this->sizeData + this->freeMemorySize];

        newData[0] = elem;
        for (i = 1; i < sizeNew; i++)
        {
            newData[i] = this->data[i - 1];
        }
        delete this->data;
        this->data = newData;
        this->sizeData = this->sizeData + 1;
        this->freeMemorySize--;
    }

    void MyArray::push_back(int elem)
    {
        if (this->freeMemorySize <= 0)
        {
            this->freeMemorySize = this->freeMemorySize + n;
        }
        int i = 0;
        int sizeNew = this->sizeData + 1;
        int *newData = new int[this->sizeData + this->freeMemorySize];

        if (this->sizeData == 0)
        {
            newData[0] = elem;
        }
        else
        {
            for (i = 0; i < sizeNew; i++)
            {
                newData[i] = this->data[i];
            }
            newData[sizeNew - 1] = elem;
        }

        delete this->data;
        this->data = newData;
        this->sizeData = sizeNew;
        this->freeMemorySize--;
    }

    void MyArray::appand_at(int elem, int index)
    {
        int newSize = this->sizeData + 1;
        int i;
        if (index < 0 || index > this->sizeData)
        {
            throw WrongArgumentException();
        }
        else
        {
            if (this->freeMemorySize <= 0)
            {
                this->freeMemorySize = this->freeMemorySize + n;
            }
            int *newData = new int[this->sizeData + this->freeMemorySize];

            if (index <= this->sizeData)
            {
                for (int i = 0; i <= newSize; i++)
                {
                    if (i < index)
                    {
                        newData[i] = this->data[i];
                    }
                    else if (i == index)
                    {
                        newData[i] = elem;
                    }
                    else if (i > index)
                    {
                        newData[i] = this->data[i - 1];
                    }
                }
            }

            delete this->data;
            this->data = newData;
            this->sizeData = newSize;
            this->freeMemorySize--;
        }
    }

    int MyArray::pop_front()
    {
        if (this->sizeData == 0)
        {
            throw ArrayIsEmptyException();
        }
        else
        {
            if (this->freeMemorySize >= (n))
            {
                this->freeMemorySize = this->freeMemorySize - (n);
            }
            int elem;
            int sizeNew = this->sizeData - 1;
            int i = 0;
            int *newData = new int[this->sizeData + this->freeMemorySize];
            elem = this->data[0];
            for (i = 1; i <= sizeNew; i++)
            {
                newData[i - 1] = this->data[i];
            }

            delete this->data;
            this->data = newData;
            this->sizeData = sizeNew;
            this->freeMemorySize++;
            return elem;
        }
    }

    int MyArray::pop_back()
    {
        if (this->sizeData == 0)
        {
            throw ArrayIsEmptyException();
        }
        else
        {
            if (this->freeMemorySize >= (n))
            {
                this->freeMemorySize = this->freeMemorySize - (n);
            }

            int elem;
            int sizeNew = this->sizeData - 1;
            int i;
            int *newData = new int[this->sizeData + this->freeMemorySize];

            for (i = 0; i < sizeNew; i++)
            {
                newData[i] = this->data[i];
            }
            elem = this->data[this->sizeData - 1];

            delete this->data;
            this->data = newData;
            this->sizeData = sizeNew;
            this->freeMemorySize++;
            return elem;
        }
    }

    int MyArray::remove_at(int index)
    {
        int elem;
        int newSize = this->sizeData - 1;

        if (index < 0 || index > newSize)
        {
            throw WrongArgumentException();
        }
        else
        {
            if (this->freeMemorySize >= (n))
            {
                this->freeMemorySize = this->freeMemorySize - (n);
            }
            int *newData = new int[this->sizeData + this->freeMemorySize];
            int i = 0;
            if (index <= this->sizeData)
            {
                for (i = 0; i <= newSize; i++)
                {
                    if (i < index)
                    {
                        newData[i] = this->data[i];
                    }
                    else if (i == index)
                    {
                        elem = this->data[i];
                    }
                    else if (i > index)
                    {
                        newData[i - 1] = this->data[i];
                    }
                }
            }
            delete this->data;
            this->data = newData;
            this->sizeData = newSize;
            this->freeMemorySize++;
            return elem;
        }
    }
}
#ifndef ITERATOR_H
#define ITERATOR_H
#include "my_string.h"
#include <string.h>

using namespace std;
namespace my_string
{
class MyStringIterator
{
private:

    char *m_ptr;

public:

    explicit MyStringIterator (char* myStr)
    {
        this->m_ptr = myStr;
    }

    // Prefix increment
    MyStringIterator& operator++()
    {
        m_ptr++;
        return *this;
    }

    // Postfix increment
    MyStringIterator operator++(int)
    {
        MyStringIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    char* operator* ()
    {
        return m_ptr;
    }

    friend bool operator== (const MyStringIterator& a, const MyStringIterator& b)
    {
        return a.m_ptr == b.m_ptr;
    }

    friend bool operator!= (const MyStringIterator& a, const MyStringIterator& b)
    {
        return a.m_ptr != b.m_ptr;
    }

};
}
#endif // ITERATOR_H

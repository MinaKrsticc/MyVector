#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include <string.h>
using namespace std;

namespace my_string
{

MyString::MyString()
{
    this->stringValue = nullptr;
}

MyString::MyString(int len)
{
    this->stringValue = new char[len + 1];
    //this->stringValue = nullptr;
}

MyString::~MyString()
{
    if(this->stringValue != nullptr)
    {
        delete this->stringValue;
        this->stringValue = nullptr;
    }
}

MyString::MyString(const char* newString)
{
    int lenght = strlen(newString);
    this->stringValue = new char[lenght + 1];
    strcpy(this->stringValue, newString);
}

MyString::MyString(const MyString& copy)
{
    int lenght = strlen(copy.stringValue);
    this->stringValue = new char[lenght + 1];
    strcpy(this->stringValue, copy.stringValue);
}

ostream& operator<<(ostream& out, const MyString& str)
{
    out << str.stringValue;
    return out;
}

istream& operator>>(istream& in, const MyString& str)
{
    in >> str.stringValue;
    return in;
}

bool MyString::operator==(const MyString& rhs)
{
    int cmpStr = strcmp(rhs.stringValue, this->stringValue);
    if(cmpStr == 0)
    {
        return true;
    }
    else return false;
}

MyString MyString::operator+(const MyString& rhs)
{
    //MyString strMy(this->stringValue);
    //MyString strMy = *this;
    if(rhs.stringValue == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }
    MyString strMy(*this);
    strMy.cat(rhs.stringValue);
    return strMy;
}

MyString MyString::operator=(const MyString& rhs)
{
    if(rhs.stringValue == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }
    if(rhs.stringValue == this->stringValue)
    {
        return *this;
    }
    else
    {
        delete [] this->stringValue;
        this->stringValue = new char [strlen(rhs.stringValue) + 1];
        strcpy(this->stringValue, rhs.stringValue);
        return *this;
    }
}

int MyString::length(MyString& str)
{
    if(str.stringValue == nullptr)
    {
        throw NullPointerException();
    }
    int i = 0;
    while(str.stringValue[i] != '\0')
    {
        i++;
    }
    return i;
}

int MyString::len()
{
    if(this->stringValue == nullptr)
    {
        throw NullPointerException();
    }
    int n = strlen(this->stringValue);
    return n;
}

void MyString::cat(char* newString)
{
    if (newString == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int lenght = strlen(newString);
    int lenThis = strlen(this->stringValue);
    char *str = new char[lenght + lenThis + 1];
    strcpy(str, this->stringValue);
    delete [] this->stringValue;
    strcat(str, newString);
    this->stringValue = str;

    //int s = stringcmp(this->stringValue, newString);
    //cout << s << endl;
}

MyString MyString::substring(int pos, int length)
{
    if (this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    MyString newStr(length);
    //MyString newStr = new char [length];
    int i = 0;
    int len = strlen(this->stringValue);

    if (pos >= 0)
    {
        if(length + pos <= len)
        {
            for(i = 0; i < length; i++)
            {
                newStr.stringValue[i] = this->stringValue[pos + i];
            }
            newStr.stringValue[length] = '\0';
        }
        else
        {
            throw InvalidArgumentException();
        }
    }
    else
    {
        throw NegativeArgumentException();
    }
    //cout<< newStr.stringValue <<endl;
    return newStr;
}

int MyString::stringcmp(char* a, char* b)
{
    if (a == nullptr || b == nullptr)
    {
        throw NullPointerException();
    }
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i = 0;
    int ret;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] == b[i])
        {
            i++;
        }
        else
        {
            ret = a[i] - b[i];
            return ret;
        }
    }
    if(i == lenA - 1 && i == lenB - 1)
    {
        return 0;
    }
    else if(a[i] == '\0' || b[i] == '\0')
    {
        ret = a[i] - b[i];
        return ret;
    }
}

bool MyString::isSubstring(char* substr)
{
    if (substr == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(substr);
    int i;
    int j;

    for( i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(this->stringValue[j] == substr[i])
                break;
        }
        if(i == m)
            return true;
    }
    return false;
}

/*bool MyString::isSubstring(char* substr)
{
    if (substr == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(substr);
    int i;
    int j = 0;
    char* pomString = new char [m + 1];
    int comp;
    if(n < m)
    {
        throw NotCorrectLenthSubStringException();
        delete [] pomString;
        return false;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if(substr[j] == this->stringValue[i])
            {
                pomString[j] = substr[j];
                j++;
            }
            if(j >= m)
            {
                comp = strcmp(substr, pomString);
                if(comp == 0)
                {
                    delete [] pomString;
                    return true;
                }
            }
        }
    }
    delete [] pomString;
    return false;
}*/

MyString MyString::append1(int pos, char* str)
{
    if (str == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    MyString newStr = this->substring(0, pos);
    newStr.cat(str);
    MyString pomStr = this->substring(pos, n - pos);
    newStr = newStr + pomStr;

    return newStr;
}

MyString MyString::append(int pos, char* str)
{
    if (str == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(str);
    MyString newStr;
    newStr.stringValue = new char [m + n];
    int i = 0;

    if(pos <= n)
    {
        for(i = 0; i < pos; i++)
        {
            newStr.stringValue[i] = this->stringValue[i];
        }
        for(i = 0; i < m; i++)
        {
            newStr.stringValue[pos + i] = str[i];
        }
        for(i = pos; i < n; i++)
        {
            newStr.stringValue[i + m] = this->stringValue[i];
        }
        newStr.stringValue[m + n] = '\0';
    }
    else
    {
        throw WrongArgumentException();
    }
    return newStr;
}


/* MyString MyString::append1(int pos, char* str)
{
    if (str == nullptr || this->stringValue == nullptr)
    {
        throw NullPointerException();
    }

    int n = strlen(this->stringValue);
    int m = strlen(str);
    MyString newStr;
    newStr.stringValue = new char [m + n];
    int i = 0;
    int j = 0;
    int k = 0;

    if(pos <= n)
    {
        while(i < m + n && k < n)
        {
            if(k == pos)
            {
                for(j = 0; j < m; j++)
                {
                    newStr.stringValue[i] = str[j];
                    i++;
                }
            }
            newStr.stringValue[i] = this->stringValue[k];
            i++;
            k++;
        }
        newStr.stringValue[m + n] = '\0';
    }
    else
    {
        throw WrongArgumentException();
    }
    return newStr;
}*/
};


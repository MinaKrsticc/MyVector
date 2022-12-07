#include <vector>
#include <iostream>
#include <string.h>
#include <exception>
#include "exception.h"
#include "my_vector.h"

using namespace std;

namespace my_vector
{
    MyVector::MyVector()
    {
        this->Head = nullptr;
    }

    MyVector::MyVector(int elem)
    {
        if (elem <= 0)
        {
            throw WrongArgumentException();
        }

        this->Head = new Node();
        this->Head->next = new Node();
        // this->Head = nullptr;
        this->Head = this->Head->next;
        this->Head->next = nullptr;
        this->Head->data = elem;
    }

    MyVector::MyVector(const MyVector &copy)
    {
        if (copy.Head == nullptr)
        {
            throw ListDoesntExist();
        }

        Node *curent = 0; 
        Node *next = 0;

        if (copy.Head == nullptr)
        {
            this->Head = nullptr;
        }
        else
        {
            this->Head = new Node;
            this->Head->data = copy.Head->data;

            curent = this->Head;
            next = copy.Head->next;
        }

        while (next != nullptr)
        {
            curent->next = new Node;
            curent = curent->next;
            curent->data = next->data;
            next = next->next;
        }
        curent->next = nullptr;
    } // konstruktor kopije

    MyVector::~MyVector()
    {
        Node *current = this->Head;
        while (current != nullptr)
        {
            Node *tmp = current;
            current = current->next;
            delete tmp;
        }
        this->Head = nullptr;
    }

    MyVector MyVector::operator=(const MyVector &rhs)
    {
        Node *ptr1 = 0; // current
        Node *ptr2 = 0; // next

        if (rhs.Head == nullptr)
        {
            this->Head = nullptr;
            throw ListDoesntExist();
        }
        else
        {
            this->Head = new Node;
            this->Head->data = rhs.Head->data;

            ptr1 = this->Head;
            ptr2 = rhs.Head->next;
        }
        while (ptr2 != nullptr)
        {
            ptr1->next = new Node;
            ptr1 = ptr1->next;
            ptr1->data = ptr2->data;
            ptr2 = ptr2->next;
        }
        ptr1->next = nullptr;
    }

    int &MyVector::operator[](int index)
    {
        Node *ptr = this->Head;
        if (index >= this->size())
        {
            throw InvalidArgumentException();
        }

        while (ptr != nullptr && index > 0)
        {
            ptr = ptr->next;
            index--;
        }
        return ptr->data;
    }

    bool MyVector::operator==(const MyVector &rhs)
    {
        if (rhs.Head == nullptr)
        {
            throw ListDoesntExist();
        }

        Node *tmpRhs = rhs.Head;
        Node *tmpThis = this->Head;
        int sizeRhs = 0;
        int sizeThis = 0;
        bool pomBool = true;
        while (tmpRhs != nullptr)
        {
            tmpRhs = tmpRhs->next;
            sizeRhs++;
        }
        while (tmpThis != nullptr)
        {
            tmpThis = tmpThis->next;
            sizeThis++;
        }
        if (sizeRhs == sizeThis)
        {
            tmpThis = this->Head;
            tmpRhs = rhs.Head;
            while (tmpThis->next != nullptr)
            {
                tmpThis = tmpThis->next;
                tmpRhs = tmpRhs->next;
                if (tmpRhs->data == tmpThis->data)
                {
                    pomBool = true;
                }
                else
                {
                    pomBool = false;
                }
            }
        }
        else
        {
            pomBool = false;
        }
        return pomBool;
    }

    ostream &operator<<(ostream &out, const MyVector &vec)
    {
        Node *tmp = vec.Head;
        while (tmp != nullptr)
        {
            out << tmp->data << "->" << endl;
            tmp = tmp->next;
        }
        return out;
    }

    int MyVector::size()
    {
        if (this->Head == nullptr)
        {
            throw ListDoesntExist();
        }

        Node *current = this->Head;
        int count = 0;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    bool MyVector::is_empty()
    {
        bool indicator = true;
        if (this->Head == nullptr || (this->Head->next == NULL && this->Head->data == 0))
        {
            return indicator;
        }
        else
        {
            indicator = false;
            return indicator;
        }
    }

    void MyVector::push_front(int elem)
    {
        if (elem <= 0)
        {
            throw InvalidArgumentException();
        }

        Node *newNode = new Node();

        newNode->data = elem;
        newNode->next = this->Head;
        this->Head = newNode;
    }

    void MyVector::push_back(int elem)
    {
        if (elem <= 0)
        {
            throw InvalidArgumentException();
        }

        Node *newNode = new Node();
        newNode->data = elem;
        newNode->next = nullptr;

        if (this->Head == nullptr)
        {
            this->Head = newNode;
            return;
        }
        Node *tmp = this->Head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }

    void MyVector::appand_at(int elem, int index)
    {
        if (elem <= 0 || index < 0)
        {
            throw InvalidArgumentException();
        }

        Node *newNode = new Node;
        int i = 1;

        if (this->Head == nullptr)
        {
            this->Head = new Node;
            this->Head->data = elem;
            return;
        }
        Node *last = this->Head;
        while (last->next != nullptr && index != i)
        {
            i++;
            last = last->next;
        }
        if (i == index)
        {
            newNode->data = elem;
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    int MyVector::pop_front()
    {
        if (this->Head == nullptr)
        {
            throw ListDoesntExist();
        }

        Node *delNode = this->Head;
        this->Head = this->Head->next;
        int tmp;
        tmp = delNode->data;
        delete delNode;
        return tmp;
    }

    int MyVector::pop_back()
    {
        int pom;
        if (this->Head == nullptr)
        {
            throw ListDoesntExist();
        }

        if (this->Head->next == NULL)
        {
            this->Head = NULL;
            return this->Head->data;
        }
        else
        {
            Node *temp = this->Head;
            while (temp->next->next != NULL) // ide dav puta next zato sto smo za prvi vec pitali u if-u a i zato sto trebamo da izbacimo poslednji tj tmp->next ciji ce da next da pokazuje na null
            {
                temp = temp->next;
            }
            pom = temp->next->data;
            Node *lastNode = temp->next; // OBA POKAZUJU NA POSLEDNJI ELEMENT
            temp->next = NULL;           // POSLEDNJI ELEMENT POKAZUJE NA NULL
            delete (lastNode);           // BRISEMO(oslobadjamo prostor) POMOCNI ZATO STO CE ON DA POKAZUJE NA ISTO STO POKAZUJE I tmp->next
            return pom;//temp->data;
        }
    }

    int MyVector::remove_at(int index)
    {
        if (index <= 0)
        {
            throw WrongArgumentException();
        }

        int i = 1; // ako indeksiranje ide od 0
        int elem;

        if (this->Head->next == NULL)
        {
            this->Head = NULL;
            elem = this->Head->data;
            return elem;
        }
        else
        {
            Node *temp = this->Head;
            while (temp->next->next != nullptr && i != index) // ide dva puta next zato sto smo za prvi vec pitali u if-u a i zato sto trebamo da izbacimo poslednji tj tmp->next ciji ce da next da pokazuje na null
            {
                temp = temp->next;
                i++;
            }
            if (i == index)
            {
                Node *iNode = temp->next; // OBA POKAZUJU NA i-ti element
                elem = temp->next->data;
                temp->next = temp->next->next; // i-ti element treba da se izbaci
                delete (iNode);
                return elem;
            }
            else
            {
                throw WrongArgumentException();
            }
        }
    }
}
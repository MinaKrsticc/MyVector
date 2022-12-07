#include <iostream>
#include <exception>
#include "my_string.h"
#include "exception.h"
#include "Iterator.h"
#include <string.h>
#include <vector>
#include <iterator>
#include "my_array.h"
#include "my_vector.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace my_string;
using namespace my_array;
using namespace my_vector;

int main()
{
   int elem = 3;
   int elemm = 6;
   MyVector vec(elem);
   cout << vec << " vector " << endl;

   int sizeVec;
   sizeVec = vec.size();
   cout << sizeVec << endl;
   vec.push_front(elemm);
   vec.appand_at(1, 1);
   cout << vec << "vec posle push fronta" << endl;

   MyVector vec1(vec);
   cout << vec1 << " vektor 1" << endl;

   bool indicatorVecEmpty = true;
   indicatorVecEmpty = vec.is_empty();
   cout << indicatorVecEmpty << endl;

   int el = 5;
   MyVector vect(el);
   vect.push_front(el);
   vect.push_front(elemm);
   cout << vect << " posle push front" << endl;

   vect.push_back(9);
   cout << vect << " posle push back" << endl;

   int sizeVect;
   sizeVect = vect.size();
   cout << sizeVect << " duzina vect!!!!" << endl;

   vect.appand_at(7, 2);
   cout << vect << " append at" << endl;

   int popf = vect.pop_front();
   cout << popf << " pop front"<<endl;
   cout << vect << " posle pop fronta" <<endl;

   int popb = vect.pop_back();
   cout << popb << " pop back"<<endl;
   cout << vect << " posle pop back" <<endl;
   int SsizeVec = vect.size();
   cout << SsizeVec << " duzina vect!!!!" << endl;


   int rem = vect.remove_at(1);
   cout << rem << " remove_at()" <<endl;
   cout << vect << " posle remove_at()" <<endl;

   if (vect == vec1)
   {
      cout << "jeste" << endl;
   }
   else
   {
      cout << "nije" << endl;
   }

   int ind = 1;
   cout << vect[ind] << endl;
   cout << "kraj 1." << endl;

   // int n = 100;
   // int m = 100;
   // int A[100][100];
   // int B[100][100];
   // int arrA[1000];

   // MyArray matricaA {};//default konstruktor moze ovako da se pozove
   // MyVector matricaB;
   // MyVector matC;

   // srand(time(0));
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = 0; j < m; j++)
   //    {
   //       int random = 1 + (rand() % 100);
   //       A[i][j] = 1 + (rand() % 100);
   //       B[i][j] = 1 + (rand() % 100);
   //       matricaA.push_back(A[i][j]);
   //       matricaB.push_back(B[i][j]);
   //    }
   // }
   // int sizeArray = matricaA.size();
   // cout << sizeArray <<endl;
   // int sum = 0;
   // for ( int i = 0; i < n; i++)
   // {
   //    for ( int j = 0; j < n; j++)
   //    {
   //       sum = 0;
   //       for (int p = 0; p < n; p++)
   //       {
   //          sum += matricaA[i] * matricaB[p];
   //       }
   //    }
   //    matC.push_back(sum);
   //    cout << sum <<endl;
   // }

   int Integer[] = {1, 2, 3, 4, 8};
   int Integerr[] = {9, 8, 9, 8, 8};
   MyArray array(Integerr, 5);
   MyArray ar{};
   int sizeD = 5;
   MyArray arr1(Integer, sizeD);
 
   MyArray arr(arr1);
   cout << arr.size() << endl;
   cout << "arr(arr1) " << endl;
   cout << arr << endl;

   bool isEmptyArr = true;
   isEmptyArr = arr1.is_empty();
   cout << endl;
   cout << "Da li je empty " << isEmptyArr << endl;

   for (int i = 0; i < 4; i++)
   {
      arr1.push_front(9);
      ar.push_back(7);
   }
   cout << endl;
   cout << arr1.size() << endl;
   cout << endl;
   cout << "arr1 push_front(9) * 4" << endl;
   cout << arr1 << endl;

   cout << endl;
   arr1.push_back(7);
   cout << ar.size() << endl;
   cout << endl;
   cout << "ar push_back(7)" << endl;
   cout << ar << endl;

   // cout << endl;
   // arr1.appand_at(3, 7);
   // cout << endl;
   // cout << " arr1.appand_at(3, 7)"<< endl;
   // cout << arr1<<endl;

   for (int i = 0; i < 6; i++)
   {
      int first;
      first = arr1.pop_front();
      cout << " arr1.pop_front(); treba da prikaze prvi element" << endl;
      cout << first << endl;
   }

   cout << endl;
   // cout << arr1.size() << endl;
   // cout << endl;
   cout << arr1 << endl;

   int back;
   back = arr1.pop_back();
   cout << " arr1.pop_back();"<< endl;
   cout << back << endl;
   cout << endl;
   cout << arr1.size() << endl;
   cout << endl;
   cout <<arr1 <<endl;

   int index;
   index = arr1.remove_at(2);
   cout << " arr1.remove_at(2);"<< endl;
   cout << index << endl;
   cout << endl;
   cout << arr1.size() << endl;
   cout << endl;
   cout <<arr1 <<endl;

       char str[] = {"str"};
       cout << str << " je str" <<endl;
       char str1[] = {"karamele"};
       cout << str1 << " je str1" <<endl;
       char str2[] = {"aleksa"};
       cout << str2 << " je str2 " <<endl;
       MyString a("aleksandar");
       cout << a << " je a" <<endl;
       MyString j("mmmmmm");
       cout << j << " je j" <<endl;
       MyString b(str2);
       MyString str3("Neki string");

       for( auto i = str3.begin(); i != str3.end(); i++)
       {
         std::cout << (*i)[0] << " OVO "<< std::endl;
       }

       if (a == b)
       {
           cout << " true" <<endl;
       }
       else
       {
           cout << " false" <<endl;
       }

      /* cout << " unesi tvoj string n: " << endl;
       cin >> n ;
       cout << n << " n je" << endl; */
    //    try
    //    {
           cout << b << " je b" <<endl;
           cout << b.isSubstring(str) << " b.isSubstring(str)" <<endl;

           MyString c(b);
           cout << c << endl;
           MyString p = c;
           cout << p << " je p" <<endl;
           MyString e = a + b;
           cout << e << " je e" <<endl;
           MyString d("hahahah");
           cout << d << endl;
           d = e + b;
           cout << d << " d = e + b" << endl;

           a.cat(str1);
           cout << a << " a.cat(str1)" << endl;
           e.cat(str);
           cout << e << " e.cat(str)" << endl;

           MyString x = a.substring(3,2);
           //MyString y;
           //y = a.substring(3, 2);
           cout << x << " je x{a.substring(3,2)};" <<endl;
           char pom[] = {"aleksa"};
           cout << d.isSubstring(pom) <<" d.isSubstring(str)" <<endl;

           cout << "je e " << e <<endl;
           cout << "je x " << x <<endl;

           x = e.append(3, str1);
           cout << x << " je x = e.append(3, str1)" <<endl;

           x = e.append1(2, str1);
           cout << x << " je x = e.append1(3, str1)" <<endl;
    //    }

    //    catch(my_base_exception& ex)
    //    {
    //        cout << ex.what() << endl;
    //    }

    //    catch(NullPointerException& ex)
    //    {
    //        cout << ex.what() << endl;
    //    }

    //    catch (NegativeArgumentException ex)
    //    {
    //        cout << ex.what() << endl;
    //    }

    //    catch (InvalidArgumentException ex)
    //    {
    //        cout << ex.what() << endl;
    //    }

    //    catch (NotCorrectLenthSubStringException ex)
    //    {
    //        cout << ex.what() <<endl;
    //    }

    //    catch (WrongArgumentException ex)
    //    {
    //        cout << ex.what() <<endl;
    //    }

    //    catch(exception& ex)
    //    {
    //        cout << "Uncaught occured!" << endl;
    //    }

   return 0;
}

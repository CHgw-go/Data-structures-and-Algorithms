#include<iostream>
#include "arraylist.h"
using namespace std;

int main()
{

    arraylist<int> a;
    arraylist<int> b(20);

    cout<< a.capacity() << ","<< b.capacity() << endl;
    return 0;
}

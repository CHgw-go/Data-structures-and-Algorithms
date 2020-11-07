#pragma once
#include<iostream>
using namespace std;
template<class T>
class arraylist
{
protected:
    T* element;            // 1D array to hold list elements
    int arraylength;       // capacity of the 1D array
    int listsize;          // number of elements in list
public:
    // constructor, copy constructor and destructor
    arraylist(int initialCapacity = 10);
    arraylist(const arraylist<T>&);
    ~arraylist() { delete[] element; }

    // output
    void output() const;

    // ADT methods

    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    int capacity() const { return arrayLength; }

    T& get(int theindex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);

};

template<class T>
inline arraylist<T>::arraylist(int initialCapacity)
{
    arraylength = initialCapacity;
    listsize = 0;
    element = new T[arraylength];
}

template<class T>
inline arraylist<T>::arraylist(const arraylist<T>& thelist)
{
    this->arraylength = thelist.arraylength;
    this->listsize = thelist.listsize;
    this->element = new T[arraylength];
    for (int i = 0; i < listsize; i++)
    {
        this->element[i] = thelist.element[i];
    }

}

template<class T>
inline T& arraylist<T>::get(int theIndex) const
{
    return element[theindex];
}

template<class T>
inline int arraylist<T>::indexOf(const T& theElement) const
{
    int index;
    for (int i = 0; i < listsize; i++)
    {
        if (element[i] == theElement)
        {
            index = i;
        }
    }
    return index;
}

template<class T>
inline void arraylist<T>::erase(int theindex)
{
    T* temp = new T[arraylengh];
    for (int i = 0; i < theindex; i++)
    {
        temp[i] = element[i];
    }
    if (theindex == listsize - 1) {};
    if (theindex < listsize - 1)
    {
        for (int i = theindex+1; i < listsize; i++)
        {
            temp[i] = element[i];
        }
    }
    element = temp;
    listsize = listsize - 1;
}

template<class T>
inline void arraylist<T>::insert(int theIndex, const T& theElement)
{
    T* temp = new T[arraylengh+1];
    for (int i=0; i < theindex; i++)
    {
        temp[i] = element[i];
    }
    if (theindex == listsize - 1)
    {
        temp[index] = theElement;
    }
    if (theindex < listsize-1)
    {
        temp[index] = theElement;
        for (int i = theindex + 1; i < listsize; i++)
        {
            temp[i] = element[i];
        }
    }
    element = temp;
    listsize = listsize + 1;
}

template<class T>
inline void arraylist<T>::output() const
{
    for (int i = 0; i < listsize; i++)
    {
        cout << element[i] << " ";
    }
    cout << endl;
}


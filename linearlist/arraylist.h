#pragma once
#include<iostream>
using namespace std;
template<class T>
class arraylist
{
protected:
    T* element;
    int arraylength;
    int listSize;
public:
    arraylist(int initialCapacity = 10);
    arraylist(const arraylist<T>&);
    ~arraylist() { delete[] element; }

    void output() const;
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    int capacity() const { return arraylength; }

    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);

    class iterator;
    iterator begin() { return iterator(element); }
    iterator end() { return iterator(element + listSize); }

    class iterator
    {
    public:
        iterator(T* thePosition = 0) { position = thePosition; }

        T& operator*() const { return *position; }
        T* operator->() const { return &position; }

        iterator& operator++()
        {
            ++position;
            return *this;
        }
        iterator operator++(int)
        {
            iterator old = *this;
            ++position;
            return old;
        }

        iterator& operator--()
        {
            --position;
            return *this;
        }
        iterator operator--(int)
        {
            iterator old = *this;
            --position;
            return old;
        }

        bool operator!=(const iterator right) const
        {
            return position != right.position;
        }
        bool operator==(const iterator right) const
        {
            return position == right.position;
        }
    protected:
        T* position;
    };
};

template<class T>
inline arraylist<T>::arraylist(int initialCapacity)
{
    arraylength = initialCapacity;
    listSize = 0;
    element = new T[arraylength];
}

template<class T>
inline arraylist<T>::arraylist(const arraylist<T>& thelist)
{
    this->arraylength = thelist.arraylength;
    this->listSize = thelist.listSize;
    this->element = new T[arraylength];
    for (int i = 0; i < listSize; i++)
    {
        this->element[i] = thelist.element[i];
    }

}

template<class T>
inline T& arraylist<T>::get(int theIndex) const
{
    return element[theIndex];
}

template<class T>
inline int arraylist<T>::indexOf(const T& theElement) const
{
    int i = 0;
    for (; i < listSize; i++)
    {
        if (element[i] == theElement)
        {
            break;
        }
    }
    return i;
}

template<class T>
inline void arraylist<T>::erase(int theindex)
{
    for (int i = theindex + 1; i < listSize; i++)
    {
        element[i - 1] = element[i];
    }
    element[listSize - 1].~T();
    listSize--;
}

template<class T>
inline void arraylist<T>::insert(int theIndex, const T& theElement)
{
    if (listSize == arraylength)
    {
        arraylength = arraylength * 2;
        T* temp = new T[arraylength];
        for (int i = 0; i < listSize; i++)
        {
            temp[i] = element[i];
        }
        delete[]element;
        element = temp;
    }
    for (int i = listSize - 1; i >= theIndex; i--)
    {
        element[i + 1] = element[i];
    }
    element[theIndex] = theElement;
    listSize++;
}

template<class T>
inline void arraylist<T>::output() const
{
    for (int i = 0; i < listSize; i++)
    {
        cout << element[i] << "  ";
    }
    cout << endl;
}

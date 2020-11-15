#pragma once
#include<iostream>

template<class T>
class maxHeap
{
private:
    int heapSize;      
    int arrayLength;  
    T* heap;   
    void changeLength();
public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() { delete[] heap; }
    bool empty() const { return heapSize == 0; }
    int size() const { return heapSize; }
    const T& top() { return heap[1]; } 
    void output() const;

    void pop();
    void push(const T&);
    void initialize(T*, int);
};

template<class T>
inline void maxHeap<T>::changeLength()
{
    T* newHeap = new T[arrayLength * 2];
    for (int p = 1; p <= heapSize; p++)
        newHeap[p] = heap[p];
    delete heap;
    heap = newHeap;
    arrayLength = arrayLength * 2;
}

template<class T>
inline maxHeap<T>::maxHeap(int initialCapacity)
{
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template<class T>
inline void maxHeap<T>::output() const
{
    for (int p = 1; p <= heapSize; p++)
    {
        std::cout << heap[p] << " ";
    }
    std::cout << std::endl;
}

template<class T>
inline void maxHeap<T>::pop()
{
    heap[1].~T;
    T lastElement = heap[heapSize--];
    int p = 1;
    int child = p * 2;
    while (child <= heapSize)
    {
        if (child < heapSize && heap[child] < heap[child + 1])
            ++child;
        if (heap[child] <= lastElement)
            break;
        
        heap[p] = heap[child];
        p = child;
        child = child * 2;
    }
    heap[p] = lastElement;
}

template<class T>
inline void maxHeap<T>::push(const T& theElement)
{
    if (heapSize == arrayLength - 1)
    {
        changeLength();
    }

    int p = ++heapSize;
    while (p != 1 && theElement >= heap[p / 2])
    {
        heap[p] = heap[p / 2];
        p = p / 2;
    }
    heap[p] = theElement;
}

template<class T>
inline void maxHeap<T>::initialize(T*theHeap, int theSize)
{
    delete heap;
    heap = theHeap;
    heapSize = theSize;

    for (int root = heapSize / 2; root >= 1; root--)
    {
        T element = heap[root];
        int p = root;
        int child = p * 2;
        while (child <= heapSize)
        {
            if (child < heapSize && heap[child] < heap[child + 1])
                ++child;
            if (heap[child] <= element)
                break;
            heap[p] = heap[child];
            p = child;
            child = child * 2;
        }
        heap[p] = element;
    }
}

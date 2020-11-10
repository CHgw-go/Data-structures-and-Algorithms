#pragma once

template<class T>
class arrayQueue
{
private:
    T* queue;
    int queueFront;
    int queueBack;
    int arrayLength; 
public:
    arrayQueue(int initCapacity=10);
    ~arrayQueue() { delete[] queue; }

    bool empty() const { return queueFront == queueBack; }
    int size() const { return (queueBack - queueFront + arrayLength) % arrayLength; }
    T& front() { return queue[(queueFront + 1) % arrayLength]; }
    T& back() { return queue[queueBack]; }
    void putout();

    void pop();
    void push(const T& theElement);
};

template<class T>
inline arrayQueue<T>::arrayQueue(int initCapacity)
{
    arrayLength = initCapacity;
    queueBack = queueFront = 0;
    queue = new T[arrayLength];
}

template<class T>
inline void arrayQueue<T>::putout()
{
    for (int i = (queueFront + 1) % arrayLength; i <= queueBack; i++)
    {
        std::cout << queue[i] << "  ";
    }
    std::cout <<std::endl;
}

template<class T>
inline void arrayQueue<T>::pop()
{
    queueFront = (queueFront + 1) % arrayLength;
    queue[queueFront].~T();
}

template<class T>
inline void arrayQueue<T>::push(const T& theElement)
{
    if ((queueBack + 1) % arrayLength == queueFront)//arraySize==arrayLength-1
    {
        T* newQueue = new T[arrayLength * 2];
        int start = (queueFront + 1) % arrayLength;
        int newStart = 0;
        if (start < 2)
        {
            for (int i = start; i <= queueBack; i++, newStart++)
            {
                newQueue[newStart] = queue[i];
            }
        }
        else
        {
            for (int i = start; i < arrayLength; i++, newStart++)
            {
                newQueue[newStart] = queue[i];
            }
            for (int i = 0; i < queueBack; i++,newStart++)
            {
                newQueue[newStart] = queue[i];
            }
        }
        queueFront = arrayLength*2 - 1;
        queueBack = arrayLength - 2;
        arrayLength = arrayLength * 2;
        delete[]queue;
        queue = newQueue;
    }
    queueBack = (queueBack + 1) % arrayLength;
    queue[queueBack] = theElement;
}

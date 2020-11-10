#pragma once
#include<iostream>
using namespace std;

template<class T>
class node
{
public:
    T element;
    node<T>* next;

    node() {}
    node(const T& element)
    {
        this->element = element;
    }
    node(const T& element, node<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};

template<class T>
class linkedQueue
{
public:
    linkedQueue()
    {
        queueFront = NULL;
        queueBack = NULL;
        queueSize = 0;
    }
    ~linkedQueue()
    {
        node<T>* nextNode = queueFront;
        while (queueFront != NULL)
        {
            nextNode = queueFront->next;
            delete queueFront;
            queueFront = nextNode;
        }
    }

    bool empty() const
    {
        return queueSize == 0;
    }
    int size() const
    {
        return queueSize;
    }
    T& front()
    {
        return queueFront->element;
    }
    T& back()
    {
        return queueBack->element;
    }
    void putout()
    {
        node<T>* p = queueFront;
        while (p != NULL)
        {
            cout << p->element << "  ";
            p = p->next;
        }
        cout << endl;
    }

    void pop();
    void push(const T&);
private:
    node<T>* queueFront;  // pointer to queue front
    node<T>* queueBack;   // pointer to queue back
    int queueSize;             // number of elements in queue
};

template<class T>
void linkedQueue<T>::pop()
{
    node<T>* nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
    queueSize--;
}

template<class T>
void linkedQueue<T>::push(const T& theElement)
{
    if (queueSize == 0)
    {
        queueFront = new node<T>(theElement, NULL);
        queueBack = queueFront;
        queueSize++;
        return;
    }
    node<T>* newNode = new node<T>(theElement, NULL);
    queueBack->next = newNode;
    queueBack = newNode;
    queueSize++;
}

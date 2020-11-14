#pragma once
#include<vector>

template <class T>
class chainNode
{
public:
    T element;
    chainNode<T>* next;

    chainNode() {}
    chainNode(const T& element)
    {
        this->element = element;
    }
    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};

template<class T>
class chain
{
protected:
    chainNode<T>* firstNode;
    int listSize;
public:
    chain();
    chain(const chain<T>&);
    ~chain();

    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void erase(T& theElement);
    void insert(int theIndex, const T& theElement);
    void output() const;

    chainNode<T>* begin() { return firstNode; }
    chainNode<T>* end()
    {
        chainNode<T>* p = firstNode;
        while (p != NULL)
        {
            p = p->next;
        }
        return p;
    }
    class iterator
    {
    protected:
        chainNode<T>* node;
    public:
        iterator(chainNode<T>* theNode = NULL)
        {
            node = theNode;
        }

        T& operator*() const { return node->element; }
        T* operator->() const { return &node->element; }

        iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator old = *this;
            node = node->next;
            return old;
        }

        bool operator!=(const iterator right) const
        {
            return node != right.node;
        }
        bool operator==(const iterator right) const
        {
            return node == right.node;
        }
    };
};

template<class T>
inline chain<T>::chain()
{
    firstNode = NULL;
    listSize = 0;
}

template<class T>
inline chain<T>::chain(const chain<T>& theChain)
{
    listSize = theChain.listSize;
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }
    firstNode = new chainNode<T>(theChain.firstNode->element);
    chainNode<T>* p = firstNode;
    chainNode<T>* tp = theChain.firstNode;
    tp = tp->next;
    while (tp != NULL)
    {
        p->next = new chainNode<T>(tp->element);
        p = p->next;
        tp = tp->next;
    }
    p->next = NULL;
}

template<class T>
inline chain<T>::~chain()
{
    while (firstNode != NULL)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
inline T& chain<T>::get(int theIndex) const
{
    chainNode<T>* p = firstNode;
    for (int i = 0; i < theIndex; i++)
    {
        p = p->next;
    }
    return p->element;
}

template<class T>
inline int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* p = firstNode;
    int i = 0;
    while (p != NULL && p->element != theElement)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template<class T>
inline void chain<T>::erase(int theIndex)
{
    chainNode<T>* p = firstNode;
    chainNode<T>* deleteNode = NULL;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        for (int i = 0; i < theIndex - 1; i++)
        {
            p = p->next;
        }
        deleteNode = p->next;
        p->next = deleteNode->next;
    }
    delete deleteNode;
    listSize--;
}

template<class T>
inline void chain<T>::erase(T& theElement)
{
    chainNode<T>* p = firstNode;
    chainNode<T>* deleteNode = NULL;
    if (p->element == theElement)
    {
        p = p->next;
        delete firstNode;
        listSize--;
        firstNode = p;
        return;
    }
    while (p->next->element != theElement)
    {
        p = p->next;
    }
    deleteNode = p->next;
    p->next = deleteNode->next;
    delete deleteNode;
    listSize--;
}

template<class T>
inline void chain<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex == 0)
    {
        firstNode = new chainNode<T>(theElement, firstNode);
    }
    else
    {
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            p = p->next;
        }
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<class T>
void chain<T>::output() const
{
    chainNode<T>* p = firstNode;
    for (; p != NULL; p = p->next)
    {
        std::cout << p->element << "  ";
    }
    std::cout << std::endl;
}

#pragma once
template <class T>
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
class chain
{
protected:
    node<T>* firstNode;
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
    void insert(int theIndex, const T& theElement);
    void output() const;

};

template<class T>
inline chain<T>::chain()
{
    firstNode = nullptr;
    listSize = 0;
}

template<class T>
inline chain<T>::chain(const chain<T>& theChain)
{
    listSize = theChain.size;
    if (listSize == 0)
    {
        firstNode = nullptr;
        return;
    }
    firstNode = new node<T>(theChain.firstNode->element);
    node<T>* p = firstNode;
    node<T>* tp = theChain.firstNode;
    while (tp != nullptr)
    {
        p->next = new node<T>(tp->element);
        p = p->next;
        tp = tp->next;
    }
    p->next = nullptr;
}

template<class T>
inline chain<T>::~chain()
{
    while (firstNode != nullptr)
    {
        node<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
inline T& chain<T>::get(int theIndex) const
{
    node<T>* p = firstNode;
    for (int i = 0; i < theIndex; i++)
    {
        p = p->next;
    }
    return p->element;
}

template<class T>
inline int chain<T>::indexOf(const T& theElement) const
{
    node<T>* p = firstNode;
    int i = 0;
    while (p != nullptr && p->element != theElement)
    {
        p = p->next;
        ++i;
    }
    if (p->next == nullptr)
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
    node<T>* p = firstNode;
    node<T>* deleteNode = nullptr;
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
}

template<class T>
inline void chain<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex == 0)
    {
        firstNode = new node<T>(theElement, firstNode);
    }
    node<T>* p = firstNode;
    for (int i = 0; i < theIndex; i++)
    {
        p = p->next;
    }
    p->next = new node<T>(theElement, p->next);
}

template<class T>
void chain<T>::output() const
{
    node<T>* p = firstNode;
    for (node<T>* p = firstNode; p != nullptr; p = p->next)
    {
        std::cout << p->element << "  ";
    }
    std::cout << std::endl;
}

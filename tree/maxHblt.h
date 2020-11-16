#pragma once
#include"binaryTree.h"
#include<queue>

using namespace std;

template<class T>
class maxHblt :public binaryTree<pair<int, T> >
{
    typedef binaryTreeNode<pair<int, T> > node;

private:
    void meld(node*,node*);
    static void hbltOutput(binaryTreeNode<pair<int, T> >* t)
    {
        cout << t->element.second << ' ';
    }
    void swap(node* x, node* y)
    {
        node* t;
        t = x;
        x = y;
        y = t;
    }
    void output(node* theNode)
    {
        std::cout << theNode->element.second << "  ";
    }
public:
    bool empty() const { return treeSize == 0; }
    int size() const { return treeSize; }
    const T& top() { return root->element.second; }
    void output()
    {
        output_in();
    }
    
    void pop();
    void push(const T&);
    void initialize(T*, int);
    void meld(maxHblt<T>& theHblt)
    {
        meld(root, theHblt.root);
        treeSize += theHblt.treeSize;
        theHblt.root = nullptr;
        theHblt.treeSize = 0;
    }

};

template<class T>
inline void maxHblt<T>::meld(node* x, node* y)
{
    if (y == nullptr) { return; }
    if (x == nullptr)
    {
        x = y;
        return;
    }
    if (x->element.second < y->element.second)
    {
        swap(x, y);
    }
    meld(x->right, y);
    if (x->left == nullptr)
    {
        x->left=x->right;
        x->right = nullptr;
        x->element.first = 1;
    }
    else
    {
        if (x->left->element.first < x->right->element.first)
            swap(x->left, x->right);
        x->element.first = x->right->element.first + 1;
    }
}

template<class T>
inline void maxHblt<T>::pop()
{
    node* left = root->left;
    node* right = root->right;
    delete root;
    root = left;
    meld(root, right);
    treeSize--;
}

template<class T>
inline void maxHblt<T>::push(const T& theElement)
{
    node* p = new node(pair<int, T>(1, theElement));
    meld(root, p);
    treeSize++;
}

template<class T>
inline void maxHblt<T>::initialize(T* theElement, int treeSize)
{
    root = 0;
    treeSize = 0;

    queue<node*> q;
    for (int i = 1; i <= treeSize; i++)
    {
        q.push(new node * (pair<int, T>(1, theElement[i])));
    }
    node* a;
    node* b;
    for (int i = 1; i < treeSize; i++)
    {
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        meld(a, b);
        q.push(a);
    }
    root = q.front();
    this->treeSize = treeSize;
}

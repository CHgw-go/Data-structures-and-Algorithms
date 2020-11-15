#include <iostream>
#include"binaryTree.h"
using namespace std;

template<class T>
void(*binaryTree<T>::visit)(binaryTreeNode<T>*) = nullptr;

int main()
{
    binaryTree<int> a, b, c, d, x;
    b.makeTree(1, a, a);
    c.makeTree(2, a, a);
    d.makeTree(3, b, c);
    x.makeTree(4, d, a);
    cout << "Number of nodes = ";
    cout << x.size() << endl;
    cout << "height = ";
    cout << x.height() << endl;
    cout << "Preorder sequence is ";
    x.putout_pre();
    cout << "Inorder sequence is ";
    x.putout_in();
    cout << "Postorder sequence is ";
    x.putout_post();
    //cout << "Level order sequence is ";
    //y.levelOrderOutput();

    return 0;
}


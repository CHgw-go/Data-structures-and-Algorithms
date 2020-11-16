#pragma once
#include<iostream>
template<class T>
class binaryTreeNode
{
public:
	T element;
	binaryTreeNode<T>* left;
	binaryTreeNode<T>* right;
	binaryTreeNode()
	{
		left = nullptr;
		right = nullptr;
	}
	binaryTreeNode(T e)
	{
		left = nullptr;
		right = nullptr;
		element = e;
	}
	binaryTreeNode(T e, binaryTreeNode<T>* left, binaryTreeNode<T>* right)
	{
		this->left = left;
		this->right = right;
		element = e;
	}
};

template<class T>
class binaryTree
{
	typedef binaryTreeNode<T> node;
	typedef binaryTree<T> tree;

protected:
	int treeSize;
	node* root;
	static void(*visit)(node*);
	static void addCount(node*)
	{
		++count;
	}
	static int count;
	static void output(node* theNode)
	{
		std::cout << theNode->element << "  ";
	}
	static void dispose(node* theNode)
	{
		delete theNode;
	}
	static int height(node* t);
public:
	binaryTree()
	{
		root = nullptr;
		treeSize = 0;
	}
	~binaryTree() {erase();}

	void makeTree(const T& theElement, binaryTree<T>& theLeft, binaryTree<T>& theRight);
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	int height() const { return height(root); }
	void erase()
	{
		visit = dispose;
		postOrder(root);
		root = nullptr;
		treeSize = 0;
	}
	int countNodes(node* theNode)
	{
		count = 0;
		visit = addCount();
		preOrder(node* theNode);
	}

	void output_pre()
	{
		visit = &output;
		preOrder(root);
		std::cout << std::endl;
	}
	void output_in()
	{
		visit = &output;
		inOrder(root);
		std::cout << std::endl;
	}
	void output_post()
	{
		visit = output;
		postOrder(root);
		std::cout << std::endl;
	}

	binaryTree<T>& removeLeftSubtree();
	binaryTree<T>& removeRightSubtree();

	void preOrder(node*);
	void inOrder(node*);
	void postOrder(node*);
	//void levelOrder(node*);
};

template<class T>
inline void binaryTree<T>::makeTree(const T& theElement, binaryTree<T>& theLeft, binaryTree<T>& theRight)
{
	root = new node(theElement, theLeft.root, theRight.root);
	treeSize = theLeft.size() + theRight.size()+1;
}

template<class T>
inline binaryTree<T>& binaryTree<T>::removeLeftSubtree()
{
	if (treeSize == 0)
	{
		return;
	}
	tree leftSubtree;
	leftSubtree.root = root->left;
	leftSubtree.treeSize = countNodes(root->left);
	root->left = nullptr;
	treeSize = treeSize - leftSubtree.treeSize;
}

template<class T>
inline binaryTree<T>& binaryTree<T>::removeRightSubtree()
{
	if (treeSize == 0)
	{
		return;
	}
	tree rightSubtree;
	rightSubtree.root = root->right;
	rightSubtree.treeSize = countNodes(root->right);
	root->right = nullptr;
	treeSize = treeSize - rightSubtree.treeSize;
}

template<class T>
inline void binaryTree<T>::preOrder(node* theRoot)
{
	if (theRoot != nullptr)
	{
		visit(theRoot);
		preOrder(theRoot->left);
		preOrder(theRoot->right);
	}
}

template<class T>
inline void binaryTree<T>::inOrder(node* theRoot)
{
	if (theRoot != nullptr)
	{
		inOrder(theRoot->left);
		visit(theRoot);
		inOrder(theRoot->right);
	}
}

template<class T>
inline void binaryTree<T>::postOrder(node* theRoot)
{
	if (theRoot != nullptr)
	{
		postOrder(theRoot->left);
		postOrder(theRoot->right);
		visit(theRoot);
	}
}

template <class T>
inline int binaryTree<T>::height(node* t)
{
	if (t == nullptr)
		return 0;                  
	int hl = height(t->left); 
	int hr = height(t->right);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}
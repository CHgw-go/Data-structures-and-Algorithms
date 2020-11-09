#pragma once
#include<iostream>

using namespace std;
template<class T>
class node
{
public:
	T data;
	node<T>* next;
	node()
	{
		next = NULL;
	}
	node(T data)
	{
		this->data = data;
	}
	node(T data,node<T>* next)
	{
		this->data = data;
		this->next = next;
	}
};

template<class T>
class linkedstack
{
private:
	int stacksize;
	node<T>* firstnode;
public:
	linkedstack()
	{
		stacksize = 0;
		firstnode = NULL;
	}
	~linkedstack()
	{
		while (firstnode != NULL)
		{
			node<T>* p = firstnode->next;
			delete firstnode;
			firstnode = p;
		}
	}
	bool empty()
	{
		return stacksize == 0;
	}
	int size()
	{
		return stacksize;
	}
	T& top()
	{
		return  firstnode->data;
	}
	void push(T thedata)
	{
		firstnode = new node<T>(thedata, firstnode);
		stacksize++;
	}
	void pop()
	{
		node<T>* p = firstnode->next;
		delete firstnode;
		firstnode = p;
		stacksize--;
	}
	void output()
	{
		node<T>* p = firstnode;
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->next;
		}
		cout << endl;
	}
};

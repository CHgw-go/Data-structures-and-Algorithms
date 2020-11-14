#pragma once
#include<iostream>
#include"chain.h"
using namespace std;
int main(void)
{
	chain<int> a;

	a.insert(0, 0);
	a.insert(0, 1);
	a.insert(0, 2);
	a.output();
	a.insert(2, 2);
	a.output();
	a.insert(a.size(), 5);
	a.output();

	cout << a.size() << endl;
	cout << a.get(2) << endl;
	cout << a.indexOf(2) << endl;
	cout << a.empty() << endl;

	a.erase(0);
	a.output();
	a.erase(a.size() - 1);
	a.output();

	chain<int> b = a;
	b.output();

	// create a chain
	chain<int> y;
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;

	// test iterator
	cout << "Ouput using forward iterators pre and post ++" << endl;
	for (chain<int>::iterator i = y.begin(); i != y.end(); i++)
		cout << *i << "  ";
	cout << endl;
	for (chain<int>::iterator i = y.begin(); i != y.end(); ++i)
	{
		cout << *i << "  ";
		*i += 1;
	}
	cout << endl;
	y.output();
	cout << endl;


}


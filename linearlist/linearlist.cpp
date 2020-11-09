#pragma once
#include<iostream>
#include"arraylist.h"
using namespace std;
int main(void)
{
	arraylist<int> a;
	a.insert(0, 0);
	a.insert(0, 1);
	a.insert(0, 2);
	a.output();
	a.insert(a.size(), 5);
	a.output();
	cout << a.get(1) << endl;
	cout << a.indexOf(5) << endl;
	cout << a.capacity() << endl;
	cout << a.empty() << endl;
	cout << a.size() << endl;
}


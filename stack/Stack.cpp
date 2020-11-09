#include<iostream>
#include"linkedstack.h"
using namespace std;
int main()
{
	linkedstack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.output();
	a.push(4);
	a.output();
	a.pop();
	a.output();
	cout<<a.size() <<endl;
	cout<<a.empty()<<endl;
	cout << a.top() << endl;
}
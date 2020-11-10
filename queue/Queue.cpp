#include<iostream>
#include"linkedQueue.h"
using namespace std;
int main()
{
	linkedQueue<int> a;
	a.push(0);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.putout();
	a.push(5);
	a.putout();
	a.pop();
	a.putout();
	a.pop();
	a.putout();

	cout << a.front() << "  " << a.back() << endl;
	cout << a.empty() << "  " << a.size() << endl;
}
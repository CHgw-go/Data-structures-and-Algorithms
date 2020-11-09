#pragma once
using namespace std;
template <class T>
class arraystack
{
private:
	int stacktop;
	int arraysize;
	T* stack;
public:
	arraystack(int initcapacity = 10)
	{
		arraysize = initcapacity;
		stacktop = -1;
		stack = new T[arraysize];
	}
	~arraystack()
	{
		delete[] stack;
	}
	bool empty()const
	{
		return stacktop == -1;
	}
	int size()const
	{
		return stacktop + 1;
	}
	T& top()
	{
		return stack[stacktop];
	}
	void pop()
	{
		stack[stacktop].~T();
		stacktop--;
	}
	void push(const T& element)
	{
		if (stacktop == arraysize-1)
		{
			T* temp = new T[arraysize * 2];
			for (int i = 0; i <= stacktop; i++)
			{
				temp[i] = stack[i];
			}
			arraysize = arraysize * 2;
			delete[]stack;
			stack = temp;
		}
		stacktop++;
		stack[stacktop] = element;
	}
	void output()
	{
		for (int i = 0; i <= stacktop; i++)
		{
			cout << stack[i] << "  ";
		}
		cout << endl;
	}
};
#pragma once
#include"Stack.h"
#include"StackNode.h"
template<class T>
class StackList :public Stack<T>
{
private:
	StackNode<T> * first;
	StackNode<T> * top;
	int nCount;
public:
	StackList();
	bool IsEmpty() const { return top == first; };
	bool Top(T & x)const;
	bool Push(T x);
	bool Pop();
	void Clear();
};


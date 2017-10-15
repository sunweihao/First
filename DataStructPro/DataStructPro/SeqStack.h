#pragma once
#include<iostream>
#include"Stack.h"
using namespace std;

#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED 

template<class T>
class SeqStack :public Stack<T>
{
private:
	int MaxTop;//最大栈顶指针
	int top;//栈顶指针
	T * s;
public:
	SeqStack(int MaxSize);
	/*SeqStack() {
		MaxTop = 19;
		s = new T[20];
		top = -1;
	};*/
	~SeqStack() { delete[] s; }
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	bool Top(T & x)const;
	bool Push(T x);
	bool Pop();
	void Clear();
};
//#include"SeqStack.cpp"
#endif
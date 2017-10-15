#pragma once
#include "SeqStack.h"

//constructor 
template<class T>
SeqStack<T>::SeqStack(int MaxSize) 
{
	MaxTop = MaxSize - 1;
	s = new T[MaxSize];
	top = -1;
}
//返回栈顶元
template<class T>
bool SeqStack<T>::Top(T & x)const {
	//判断栈是否为空
	if (IsEmpty())
	{
		cout << "No element in the stack!" << endl;
		return false;
	}
	x = s[top];
	return true;
}
//向栈中压入一个元素
template<class T>
bool SeqStack<T>::Push(T x) {
	//判断栈是否已满
	if (IsFull())
	{
		cout << "The stack is already full!" << endl;
		return false;
	}
	top++;
	s[top] = x;
	return true;
}
//从栈顶删除一个元素
template<class T>
bool SeqStack<T>::Pop() {
	//判断栈是否为空
	if (IsEmpty())
	{
		cout << "No element in the stack!" << endl;
		return false;
	}
	top--;
	return true;
}
//清空栈
template<class T>
void SeqStack<T>::Clear() {
	top = -1;
	//return true;
}

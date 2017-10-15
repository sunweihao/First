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
//����ջ��Ԫ
template<class T>
bool SeqStack<T>::Top(T & x)const {
	//�ж�ջ�Ƿ�Ϊ��
	if (IsEmpty())
	{
		cout << "No element in the stack!" << endl;
		return false;
	}
	x = s[top];
	return true;
}
//��ջ��ѹ��һ��Ԫ��
template<class T>
bool SeqStack<T>::Push(T x) {
	//�ж�ջ�Ƿ�����
	if (IsFull())
	{
		cout << "The stack is already full!" << endl;
		return false;
	}
	top++;
	s[top] = x;
	return true;
}
//��ջ��ɾ��һ��Ԫ��
template<class T>
bool SeqStack<T>::Pop() {
	//�ж�ջ�Ƿ�Ϊ��
	if (IsEmpty())
	{
		cout << "No element in the stack!" << endl;
		return false;
	}
	top--;
	return true;
}
//���ջ
template<class T>
void SeqStack<T>::Clear() {
	top = -1;
	//return true;
}

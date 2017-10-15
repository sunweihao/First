#include "StackList.h"

template<class T>
StackList<T>::StackList() {
	first = top = NULL;
	nCount = 0;
}

template<class T>
bool StackList<T>::Top(T & x)const {
	//判断链表是否为空
	if (IsEmpty())
	{
		cout << "No element in the StackList!" << endl;
		return false;
	}
	x = top->element;
	return true;
}

template<class T>
bool StackList<T>::Push(T x) {
	StackNode<T> * q = new StackNode<T>();
	q->element = x;
	top->next = q;
	top = top->next;
	nCount++;
}
template<class T>
bool StackList<T>::Pop() {
	//判断链表是否为空
	if (IsEmpty())
	{
		cout << "No element in the StackList!" << endl;
		return false;
	}
	StackNode<T> * pBefore = first;
	for (int i = 0; i < nCount-1; i++)
	{
		pBefore = pBefore->next;
	}
	delete top;
	top = pBefore;
	nCount--;
	return true;
}
template<class T>
void StackList<T>::Clear()
{
	StackNode<T> * p = first;
	StackNode<T> * q = first;
	while (p != NULL)
	{
		q->next = p->next;
		delete p;
		p = q->next;
	}
	first = q = top = NULL;
}

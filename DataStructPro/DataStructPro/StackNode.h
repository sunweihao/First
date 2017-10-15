#pragma once
#include<iostream>
using namespace std;
template<class T>
class StackList;
template<class T>
class StackNode
{
private:
	T element;
	StackNode<T> * next;
	friend class StackList<T>;
};


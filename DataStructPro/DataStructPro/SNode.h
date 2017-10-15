#pragma once
#include"SingleList.h"
template<class T> 
class SingleList;
template<class T>
class SNode {
private:
	T element;
	SNode<T> * next;
	friend class SingleList<T>;
};
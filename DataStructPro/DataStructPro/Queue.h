#pragma once
#include<iostream>
using namespace std;
template<class T>
class Queue
{
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Front(T & x)const = 0;
	virtual bool EnQueue(T x) = 0;
	virtual bool DeQueue() = 0;
	virtual void Clear() = 0;
};


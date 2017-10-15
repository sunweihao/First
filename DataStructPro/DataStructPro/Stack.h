#pragma once
#include<iostream>
template<class T>
class Stack {
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Top(T & x)const =0;
	virtual bool Push(T x) = 0;
	virtual bool Pop() = 0;
	virtual void Clear() = 0;
};
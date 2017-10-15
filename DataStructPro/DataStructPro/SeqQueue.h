#pragma once
#include"Queue.h"
template<class T>
class SeqQueue:public Queue<T>
{
private:
	int front, rear;
	int MaxSize;
	T * s;
public:
	SeqQueue(int maxSize);
	~SeqQueue() { delete[] s; 	};
	bool IsEmpty() const { return rear == front; };
	bool IsFull() const { return (rear + 1) % MaxSize == front;	};
	bool Front(T & x)const;
	bool EnQueue(T x);
	bool DeQueue();
	void Clear();
};


#include "SeqQueue.h"


template<class T>
SeqQueue<T>::SeqQueue(int maxSize):MaxSize(maxSize)
{
	front = rear = 0;
	s = new T[maxSize];
}

template<class T>
bool SeqQueue<T>::Front(T & x)const {
	//判断队列是否为空
	if (IsEmpty())
	{
		cout << "No element in the Queue!" << endl;
		return false;
	}
	x = s[(front + 1) % MaxSize];
	return true;
}
template<class T>
bool SeqQueue<T>::EnQueue(T x) {
	if (IsFull())
	{
		cout << "The queue is already full!" << endl;
		return false;
	}
	rear = (rear + 1) % MaxSize;
	s[rear] = x;
	return true;
}

template<class T>
bool SeqQueue<T>::DeQueue() {
	//判断队列是否为空
	if (IsEmpty())
	{
		cout << "No element in the Queue!" << endl;
		return false;
	}
	front = (front + 1) % MaxSize;
	return true;
}
template<class T>
void SeqQueue<T>::Clear() {
	front = rear = 0;
}
#pragma once
#include"LinearList.h"
using namespace std;
template<class T >
class SeqList :public LinearList<T>
{
private:
	int nMaxLength;//顺序表的最大长度
	T * elements;//动态一维数组指针
public:
	SeqList(int mSize);
	~SeqList()
	{
		delete[] elements;
	}
	bool IsEmpty() const;
	int Length() const;
	bool Find(int i, T & x)const;
	bool Search(T  x) const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	void Output(ostream & out)const;
};
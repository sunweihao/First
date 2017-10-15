#pragma once
#include"LinearList.h"
#include"SNode.h"
using namespace std;
template<class T>
class SingleList
{
private:
	SNode<T> * first;
public:
	SingleList() { first = NULL, n = 0 };
	/*若为带表头结点的链表则
	first = new SNode();
	first->next =NULL;
	n =0;
	*/
	~SingleList();
	bool IsEmpty() const;
	int Length() const;
	bool Find(int i, T & x)const;
	bool Search(T  x) const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	void Output(ostream & out)const;
};


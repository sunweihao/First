#include "SingleList.h"
//判断链表是否为空
template<class T>
bool SingleList<T>::IsEmpty()const {
	return n == 0;
}
//返回链表长度
template<class T>
int SingleList<T>::Length()const {
	return n;
}
//在指定位置插入一个节点
template<class T>
bool SingleList<T>::Insert(int i, T x) {
	if (i < -1 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	SNode<T> * q = first;
	SNode<T> * p = new SNode();
	p->element = x;
	//若要插入到第一个节点之前
	if (i == -1)
	{
		p->next = q;
		q = p;
		n++;
		return true;
	}
	for (int j = -1; j < i; j++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	n++;
	return true;
}
//若为带表头的链表 插入时无需分辨是否要插在第一个节点前面  同理删除时也无须分辨是否为头节点
//template<class T>
//bool SingleList<T>::Insert(int i, T x) {
//	if (i < -1 || i > n - 1)
//	{
//		cout << "Out of index!" << endl;
//		return false;
//	}
//	SNode<T> * q = first;
//	SNode<T> * p = new SNode();
//	p->element = x;
//	for (int j = -1; j < i; j++)
//	{
//		q = q->next;
//	}
//	p->next = q->next;
//	q->next = p;
//	n++;
//	return true;
//}

template<class T>
SingleList<T>::~SingleList()
{
	SNode<T> * p = first;
	SNode<T> * pTemp = first;
	while (p != NULL)
	{
		p = first->next;
		delete first;
		first = p;
	}
	pTemp = NULL;
}
//将下标为i的节点的数据传给x
template<class T>
bool SingleList<T>::Find(int i, T & x)const {
	//判断数组越界
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	SNode<T> * pNode = first;
	for (int j = 0; j < i; j++)
	{
		pNode = pNode->next;
	}
	x = pNode->element;
	return true;
}
//判断 x 是不是链表中存储的数据值
template<class T>
bool SingleList<T>::Search(T x)const {
	SNode<T> * pNode = first;
	for (int i = 0; i < n; i++)
	{
		if (pNode->element == x)
			return true;
		pNode = pNode->next;
	}
	return false;
}
//删除一个节点
template<class T>
bool SingleList<T>::Delete(int i) {
	//判断链表是否为空
	if (0 == n)
	{
		cout << "no node in the list!" << endl;
		return false;
	}
	//判断数组越界
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	SNode<T> * pNode = first;
	SNode<T> * pBefore = first;
	//判断是否删除第一个元素
	if ( i == 0)
	{
		first = first->next;
		delete pNode;
		pNode = NULL;
		pBefore = NULL;
		return true;
		n--;
	}
	for (int j = 0; j < i; j++)
	{
		pBefore = pNode;
		pNode = pNode->next;
	}
	pBefore->next = pNode->next;
	delete pNode;
	pNode = NULL;
	n--;
	return true;
}
//将下标为i的节点存储的数据值换为x
template<class T>
bool SingleList<T>::Update(int i, T x) {
	//判断是否越界
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	SNode<T> * pNode = first;
	for (int j = 0; j < i; j++)
	{
		pNode = pNode->next;
	}
	pNode->element = x;
	return true;
}
//输出链表
template<class T>
void SingleList<T>::Output(ostream & out)const {
	SNode<T> * pNode = first;
	while (pNode != NULL)
	{
		out << pNode->element << " ";
		pNode = pNode->next;
	}
	out << endl;
}

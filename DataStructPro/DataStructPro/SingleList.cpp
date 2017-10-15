#include "SingleList.h"
//�ж������Ƿ�Ϊ��
template<class T>
bool SingleList<T>::IsEmpty()const {
	return n == 0;
}
//����������
template<class T>
int SingleList<T>::Length()const {
	return n;
}
//��ָ��λ�ò���һ���ڵ�
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
	//��Ҫ���뵽��һ���ڵ�֮ǰ
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
//��Ϊ����ͷ������ ����ʱ����ֱ��Ƿ�Ҫ���ڵ�һ���ڵ�ǰ��  ͬ��ɾ��ʱҲ����ֱ��Ƿ�Ϊͷ�ڵ�
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
//���±�Ϊi�Ľڵ�����ݴ���x
template<class T>
bool SingleList<T>::Find(int i, T & x)const {
	//�ж�����Խ��
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
//�ж� x �ǲ��������д洢������ֵ
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
//ɾ��һ���ڵ�
template<class T>
bool SingleList<T>::Delete(int i) {
	//�ж������Ƿ�Ϊ��
	if (0 == n)
	{
		cout << "no node in the list!" << endl;
		return false;
	}
	//�ж�����Խ��
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	SNode<T> * pNode = first;
	SNode<T> * pBefore = first;
	//�ж��Ƿ�ɾ����һ��Ԫ��
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
//���±�Ϊi�Ľڵ�洢������ֵ��Ϊx
template<class T>
bool SingleList<T>::Update(int i, T x) {
	//�ж��Ƿ�Խ��
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
//�������
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

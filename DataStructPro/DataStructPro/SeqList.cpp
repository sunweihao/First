#include"SeqList.h"
//���캯��
template<class T>
SeqList<T>::SeqList(int mSize) {
	nMaxLength = mSize;
	elements = new T[nMaxLength];
	n = 0;
}
//�ж�˳����Ƿ�Ϊ��
template<class T>
bool SeqList<T>::IsEmpty()const {
	return n == 0;
}
//����˳�����
template<class T>
int SeqList<T>::Length()const {
	return n;
}
//���±�Ϊi��Ԫ�ظ�ֵ��x
template<class T>
bool SeqList<T>::Find(int i, T & x) const{
	//�ж������Ƿ�Խ��
	if (i < 0 || i > n-1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	x = elements[i];
	return true;
}
//��˳�����Ѱ��xԪ��
template<class T>
bool SeqList<T>::Search(T x)const {
	for (int i = 0; i < n; i++)
	{
		if (elements[i] == x) return true;
	}
	return false;
}
//��˳����в���һ��Ԫ��
template<class T>
bool SeqList<T>::Insert(int i, T x) {
	if (i < -1 || i > n-1)
	{
		cout << "Out of Index!" << endl;
		return false;
	}
	for (int j = n-1 ; j > i; j--) {
		elements[j + 1] = elements[j];
	}
	elements[i + 1] = x;
	n++;
	return true;
}
//ɾ��һ��Ԫ��
template<class T>
bool SeqList<T>::Delete(int i) {
	//�ж������Ƿ�Ϊ��
	if (n == 0)
	{
		cout << "no data in the array!" << endl;
		return false;
	}
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	for (int j = i; j < n-1; j++) {
		elements[j] = elements[j + 1];
	}
	n--;
	return true;
}
//���±�Ϊi��Ԫ���޸�Ϊx
template<class T>
bool SeqList<T>::Update(int i, T x) {
	if (i < 0 || i > n - 1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	elements[i] = x;
	return true;
}
//���˳���
template<class T>
void SeqList<T>::Output(ostream & out)const {
	for (int i = 0; i < n; i++)
	{
		out << elements[i] << " ";
	}
	out << endl;
}


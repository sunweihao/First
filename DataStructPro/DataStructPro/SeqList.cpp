#include"SeqList.h"
//构造函数
template<class T>
SeqList<T>::SeqList(int mSize) {
	nMaxLength = mSize;
	elements = new T[nMaxLength];
	n = 0;
}
//判断顺序表是否为空
template<class T>
bool SeqList<T>::IsEmpty()const {
	return n == 0;
}
//返回顺序表长度
template<class T>
int SeqList<T>::Length()const {
	return n;
}
//将下标为i的元素赋值给x
template<class T>
bool SeqList<T>::Find(int i, T & x) const{
	//判断数组是否越界
	if (i < 0 || i > n-1)
	{
		cout << "Out of index!" << endl;
		return false;
	}
	x = elements[i];
	return true;
}
//在顺序表中寻找x元素
template<class T>
bool SeqList<T>::Search(T x)const {
	for (int i = 0; i < n; i++)
	{
		if (elements[i] == x) return true;
	}
	return false;
}
//在顺序表中插入一个元素
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
//删除一个元素
template<class T>
bool SeqList<T>::Delete(int i) {
	//判断数组是否为空
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
//将下标为i的元素修改为x
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
//输出顺序表
template<class T>
void SeqList<T>::Output(ostream & out)const {
	for (int i = 0; i < n; i++)
	{
		out << elements[i] << " ";
	}
	out << endl;
}


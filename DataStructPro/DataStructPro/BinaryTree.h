#pragma once
#include"BTNode.h"
template<class T>
class BinaryTree
{
public:
	BinaryTree() { root = NULL; }
	~BinaryTree();
	bool IsEmpty()const;
	void Clear();
	bool Root(T & x)const;
	void MakeTree(const T & x, BinaryTree<T> &left, BinaryTree<T> & right);
	void BreakTree(T & x, BinaryTree<T> &left, BinaryTree<T> & right);
	void PreOrder(void(*Visit)(T &x));
	void InOrder(void(*Visit)(T &x));
	void PostOrder(void(*Visit)(T &x));
	int Size();
	BTNode<T> * Copy(BTNode<T> * t);
	int Height();
	int LeaveNum();
	//void Visit(T & x);
protected:
	BTNode<T> * root;
private:
	int Size(BTNode<T> * t);
	void Clear(BTNode<T> * t);
	void PreOrder(void(*Visit)(T &x),BTNode<T> * t);
	void InOrder(void(*Visit)(T &x), BTNode<T> * t);
	void PostOrder(void(*Visit)(T &x), BTNode<T> * t);
	int Height(BTNode<T> * t);
	int LeaveNum(BTNode<T> * t);
};


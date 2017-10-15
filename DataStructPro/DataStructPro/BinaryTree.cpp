#include "BinaryTree.h"
#include<algorithm>
template<class T>
BinaryTree<T>::~BinaryTree()
{
	Clear();
}
template<class T>
void BinaryTree<T>::Clear() {
	Clear(root); root = NULL;
}
template<class T>
void BinaryTree<T>::Clear(BTNode<T> * t) {
	if (t) {
		Clear(t->getLChild());
		Clear(t->getRChild());
		delete t;
		//t = NULL;
	}
}
template<class T>
bool BinaryTree<T>::IsEmpty()const {
	return root;
}

template<class T>
bool BinaryTree<T>::Root(T & x)const {
	if (root) {
		x = root->element;
		return true;
	}
	else return false;
}
template<class T>
void BinaryTree<T>::MakeTree(const T & x, BinaryTree<T> &left, BinaryTree<T> & right) {
	if (root || (&left == &right))
	{
		return;
	}
	root = new BTNode<T>(x, left.root, right.root);
	left.root = right.root = NULL;
}
template<class T>
void BinaryTree<T>::BreakTree(T & x, BinaryTree<T> &left, BinaryTree<T> & right) {
	if (!root || &left == &right || left.root || right.root)
	{
		return;
	}
	x = root->element;
	left.root = root->lChild;
	right.root = root->rChild;
	delete root;
	root = NULL;
}

//前序遍历
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T &x), BTNode<T> * t) {
	if (t)
	{
		Visit(t->GetElement());
		PreOrder(Visit, t->getLChild());
		PreOrder(Visit, t->getRChild());
	}
}
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(T &x)) {
	PreOrder(Visit, root);
}
//中序遍历
template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T &x), BTNode<T> * t) {
	if (t)
	{
		InOrder(Visit, t->getLChild());
		Visit(t->GetElement());
		InOrder(Visit, t->getRChild());
	}
}
template<class T>
void BinaryTree<T>::InOrder(void(*Visit)(T &x)) {
	InOrder(Visit, root);
}
//后序遍历
template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T &x), BTNode<T> * t) {
	if (t)
	{
		PostOrder(Visit, t->getLChild());
		PostOrder(Visit, t->getRChild());
		Visit(t->GetElement());
	}
}
template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(T &x)) {
	PostOrder(Visit, root);
}
//节点数
template<class T>
int BinaryTree<T>::Size() {
	Size(root);
}
template<class T>
int BinaryTree<T>::Size(BTNode<T> * t) {
	if (!t)
	{
		return 0;
	}
	else return Size(t->lChild) + Size(t->rChild) + 1;
}
//复制二叉树
template <class T>
BTNode<T> * BinaryTree<T>::Copy(BTNode<T> * t) {
	if (!t) return NULL;
	BTNode<T> * qR = new BTNode<T>(t->element);
	qR->lChild = Copy(t->lChild);
	qR->rChild = Copy(t->rChild);
	return qR;
}
//求二叉树高度
template<class T>
int BinaryTree<T>::Height(BTNode<T> * t) {
	if (!t) return 0;
	else
	{
		return std::max(Height(t->getLChild()), Height(t->getRChild())) + 1;
	}
}
//求叶子节点数目
template<class T>
int BinaryTree<T>::LeaveNum(BTNode<T> * t) {
	if (!(t->getLChild() || t->getRChild())) return 1;
	else return LeaveNum(t->getLChild()) + LeaveNum(t->getRChild());
}
template<class T>
int BinaryTree<T>::Height() {
	return Height(root);
}
template<class T>
int BinaryTree<T>::LeaveNum() {
	return LeaveNum(root);
}
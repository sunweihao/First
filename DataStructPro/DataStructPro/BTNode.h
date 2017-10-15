#pragma once
template<class T>
class  BTNode
{
public:
	BTNode() {
		lChild = rChild = NULL;
	 }
	BTNode(const T & x) {
		element = x;
		lChild = rChild = NULL;
	}
	BTNode(const T & x, BTNode<T> * l, BTNode<T> * r) {
		element = x;
		lChild = l;
		rChild = r;
	}
	T & GetElement() {
		return element;
	}
	BTNode<T> * getLChild() {
		return lChild;
	}
	BTNode<T> * getRChild() {
		return rChild;
	}
private:
	T element;
	BTNode<T> * lChild, * rChild;
};

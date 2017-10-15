#include<iostream>
#include"SeqList.h"
#include"Polynominal.h"
#include"SingleList.h"
#include"Calculator.h"
#include"stdlib.h"
#include"SeqStack.h"
#include"SeqStack.cpp"
#include"BinaryTree.h"
#include"BinaryTree.cpp"
#include"BTNode.h"
using namespace std;
const int SIZE = 20;
void Visit(char & x) {
	cout << x << "  ";
}
void main()
{
	//test Polynominal
	/*Polynominal p, q, r;
	cin >> p;
	cout << p;
	cin >> q;
	cout << q;
	p = p + q;
	cout << p;
	p.PolyDerivation(r);
	cout << r;
	system("pause");*/

	//test Calculator
	//Calculator c(SIZE);
	//c.Run();
	//c.InFixToPostFix();
	//system("pause");
	
	BinaryTree<char> a, b, c, x, y,z,w,d,e;

	
	
	x.MakeTree('X', d, e);
	y.MakeTree('Y', d, e);a.MakeTree('A', x, y);
	z.MakeTree('Z', d, e);
	w.MakeTree('W', d, e);b.MakeTree('B', z, w);
	c.MakeTree('C', a, b);
	c.PreOrder(Visit);
	cout << endl;
	c.InOrder(Visit);
	cout << endl;
	c.PostOrder(Visit);
	cout << endl;
	cout << c.Height() << "\t" << c.LeaveNum() << endl;
	system("pause");
}

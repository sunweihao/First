#pragma once
#include"Term.h"

class Polynominal
{
private:
	Term * theList;
public:
	Polynominal() { theList = new Term(0, -1); theList->next = theList; }
	~Polynominal();
	void AddTerms(istream & in);//创建多项式链表
	void Output(ostream & out)const;//输出多项式
	void PolyAdd(Polynominal & r);//多项式相加
	void PolyDerivation(Polynominal & r);//多项式求导
	friend ostream & operator<<(ostream & out, const Polynominal & x);
	friend istream & operator >> (istream & in, Polynominal & x);
	friend Polynominal & operator + (Polynominal & x1, Polynominal & x2);
};


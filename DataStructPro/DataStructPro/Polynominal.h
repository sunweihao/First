#pragma once
#include"Term.h"

class Polynominal
{
private:
	Term * theList;
public:
	Polynominal() { theList = new Term(0, -1); theList->next = theList; }
	~Polynominal();
	void AddTerms(istream & in);//��������ʽ����
	void Output(ostream & out)const;//�������ʽ
	void PolyAdd(Polynominal & r);//����ʽ���
	void PolyDerivation(Polynominal & r);//����ʽ��
	friend ostream & operator<<(ostream & out, const Polynominal & x);
	friend istream & operator >> (istream & in, Polynominal & x);
	friend Polynominal & operator + (Polynominal & x1, Polynominal & x2);
};


#include "Polynominal.h"

void Polynominal::AddTerms(istream & in) {
	int c, e;
	Term * p = theList;
	int eBefore=-1;
	int nCount = 1;
	//������˳�����루coef��exp����e<0ʱ����
	while (true)
	{
	input:		
		cout << "������˳�����루coef��exp��:" << endl;
		in >> c >> e;
		if (e >= eBefore && nCount ==0)
		{
			cout << "�밴����˳���������ʽ��" << endl;
			goto input;
		}
		nCount = 0;
		eBefore = e;
		p = p->InsertAfter(c, e);
		if (e < 0)
		{
			cout << "������ϣ�" << endl;
			break;
		}
	}
}
void Polynominal::Output(ostream & out)const {
	Term * p = theList->next;
	int nCount = 1;
	cout << "The polynominal is:" << endl;
	while (p != theList)
	{
		if (!nCount &&(p->coef>0))
		{
			cout << " + ";
			
		}
		nCount = 0;
		out << *p;
		p = p->next;
	}
	cout << endl;
}
void Polynominal::PolyAdd(Polynominal & r) {
	Term * p = r.theList->next;
	Term * q = theList->next;
	Term * qTemp = theList;
	while (p->exp >= 0)
	{
		if (p->exp < q->exp)
		{
			qTemp = q;
			q = q->next;
		}
		else if (p->exp == q->exp)
		{
			if (p->coef + q->coef == 0)
			{
				qTemp->next = q->next;
				delete q;
				q = qTemp->next;
			}
			else {
				q->coef = p->coef + q->coef;
				qTemp = q;
				q = q->next;
			}
			p = p->next;
		}
		else
		{
			//qTemp->next = q;
			qTemp = qTemp->InsertAfter(p->coef, p->exp);
			//qTemp = qTemp->next;
			p = p->next;
		}
		
	}
	
}
//����ʽ�� ����rΪһ���ն���ʽ��������ã���������󵼺�Ķ���ʽ
void Polynominal::PolyDerivation(Polynominal & r) {
	Term * p = theList->next;
	Term * q = r.theList->next;
	while (p->exp>=1)
	{
		q = q->InsertAfter(p->coef*p->exp, p->exp-1);
		p = p->next;
	}
}
Polynominal::~Polynominal()
{
	Term * q = theList->next;
	Term * qTemp=theList;
	while (q != theList)
	{
		qTemp->next = q->next;
		delete q;
		q = qTemp->next;
	}
	delete q;
	q = NULL;
	qTemp = NULL;
	theList = NULL;
}
ostream & operator<<(ostream & out, const Polynominal & x) {
	x.Output(out);
	return out;
}
istream & operator >> (istream & in, Polynominal & x) {
	x.AddTerms(in);
	return in;
}
Polynominal & operator + (Polynominal & x1, Polynominal & x2) {
	x1.PolyAdd(x2);
	return x1;
}
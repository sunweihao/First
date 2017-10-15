#include "Term.h"



Term::Term(int c,int e):coef(c),exp(e)
{
	next = NULL;
}
Term::Term(int c, int e,Term * nxt) : coef(c), exp(e)
{
	next = nxt;
}
Term * Term::InsertAfter(int c, int e) {
	next = new Term(c, e,next);
	return next;
}
//输出多项式的一项
ostream & operator<<(ostream & out, const Term & term) {
	if (term.coef == 0)
	{
		return out;
	}
	cout << term.coef;
	switch (term.exp)
	{
	case 0:
		break;
	case 1:
		cout << "x";
		break;
	default:
		cout << "x^" << term.exp;
		break;
	}
	return out;
}
Term::~Term()
{
}

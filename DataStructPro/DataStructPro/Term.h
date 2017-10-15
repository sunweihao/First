#include<iostream>
using namespace std;

class Polynominal;
class Term
{
private:
	int coef;
	int exp;
	Term * next;
public:
	Term(int c,int e);
	Term(int c, int e, Term * nxt);
	~Term();
	Term * InsertAfter(int c, int e);
	friend ostream & operator<<(ostream & out, const Term & term);
	friend class Polynominal;
};


#include "Calculator.h"
#include<string>
//将操作数压入栈中
void Calculator::PushOperands(double op) {
	sta.Push(op);
}
//从栈中探出两个操作数
bool Calculator::GetOperands(double & op1,double & op2)
{
	if (!sta.Top(op1))return false;
	sta.Pop();
	if (!sta.Top(op2))return false;
	sta.Pop();
	return true;
}
//根据相应操作符进行相应运算
void Calculator::DoOperator(char o) {
	bool result;
	double op1, op2;
	result = GetOperands(op1, op2);
	if (result)
	{
		switch (o) {
		case '+': PushOperands(op1 + op2); break;
		case '-':PushOperands(op2 - op1); break;
		case '*':PushOperands(op1*op2); break;
		case '/':if (op1 == 0) {
			cout << "分母为0" << endl;
			ClearCal();
			break;}
				  else PushOperands(op2 / op1); break;
		case '^':PushOperands(pow(op2, op1)); break;
		}
	}
	else {
		cout << "不能获得操作数！清空栈！" << endl;
		ClearCal();
	}
}

void Calculator::Run()
{
	cout << "请逐项输入后缀表达式：" << endl;
	char opr; double newOp;
	//while ((cin>>opr) && (opr!='#'))
Input:	cin >> opr;
	while(opr != '#')
	{
		
		switch (opr) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			DoOperator(opr); goto Input;
		default:
			cin.putback(opr);
			cin >> newOp;
			PushOperands(newOp);
			goto Input;
		}
	}
	sta.Top(newOp);
	cout << "the result is:" + to_string(newOp) << endl;
}
//栈内运算符优先级
int Calculator::Isp(char c) {
	switch (c)
	{
	case '#':
		return 0;
	case '+':
	case '-':
		return 3;
	case '*':
	case '/':
		return 5;
	case '^':
		return 7;
	case '(':
		return 1;
	default:
		return -1;
	}
}
//栈外运算符优先级
int Calculator::Icp(char c) {
	switch (c)
	{
	case '#':
		return 0;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 4;
	case '^':
		return 6;
	case '(':
		return 8;
	default:
		return -1;
	}
}
void Calculator::InFixToPostFix() {
	char ch,y;
	cout << "请逐项输入中缀表达式：" << endl;
	string fixS = "中缀表达式为";
	while ((cin>>ch)&&(ch != '#'))
	{
		if (isdigit(ch) || isalpha(ch)) fixS += ch;//cout << ch;
		else if (ch == ')') {
			for (fix.Top(y),fix.Pop();y != '(';fix.Top(y),fix.Pop())
			{
				fixS += y;//cout << y;
			}
		}
		else {
			fix.Top(y);
			if(Icp(ch) >Isp(y) )
			{
				fix.Push(ch);
			}
			else
			{
				while (Icp(ch) <= Isp(y))
				{
					fixS += y;//cout << y;
					fix.Pop();
					fix.Top(y);
				}
				fix.Push(ch);
			}
		}
	}
	while (fix.Top(y)&& y!='#')
	{
		fixS += y;//cout << y;
		fix.Pop();
	}
	cout << fixS;
}
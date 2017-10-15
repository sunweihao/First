#include "Calculator.h"
#include<string>
//��������ѹ��ջ��
void Calculator::PushOperands(double op) {
	sta.Push(op);
}
//��ջ��̽������������
bool Calculator::GetOperands(double & op1,double & op2)
{
	if (!sta.Top(op1))return false;
	sta.Pop();
	if (!sta.Top(op2))return false;
	sta.Pop();
	return true;
}
//������Ӧ������������Ӧ����
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
			cout << "��ĸΪ0" << endl;
			ClearCal();
			break;}
				  else PushOperands(op2 / op1); break;
		case '^':PushOperands(pow(op2, op1)); break;
		}
	}
	else {
		cout << "���ܻ�ò����������ջ��" << endl;
		ClearCal();
	}
}

void Calculator::Run()
{
	cout << "�����������׺���ʽ��" << endl;
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
//ջ����������ȼ�
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
//ջ����������ȼ�
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
	cout << "������������׺���ʽ��" << endl;
	string fixS = "��׺���ʽΪ";
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
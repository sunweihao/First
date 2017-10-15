#pragma once
#include"SeqStack.h"
#include"math.h"
class Calculator
{
private:
	SeqStack<double> sta;
	SeqStack<char> fix;
	void PushOperands(double op);
	bool GetOperands(double & op1, double & op2);
	void DoOperator(char o);
public:
	Calculator(int maxSize) :sta(maxSize), fix(maxSize) { fix.Push('#'); }
	void Run();
	void ClearCal() { sta.Clear(); }
	void InFixToPostFix();//��׺���ʽת��׺
	int Isp(char c);//ջ����������ȼ�
	int Icp(char c);//ջ����������ȼ�
};


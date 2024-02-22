#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "..\stack\lib\stack_lib.h"
#include "func.h"
using namespace std;

const double PI = 3.141592653589793;
const double E  = 2.718281828459045;

//�������� ��������
string RemoveSpace(string s);

//�������� �� ������ �����
string Remove0(string s);

//�������� �� ����������� ��������� �������
bool CheckFormula(string s);

//���������� � ����� � i �������
double ToDouble(string s, int& i);

//���������� � ��������� ���������� � i �������
string ToStringVar(string s, int& i);

//�������� �� �����
bool CheckNumber(char c);

//�������� �� ������
bool CheckChar(char c);

//�������� �� ������� ��������
bool CheckOperator(char c);
bool CheckOperator(string s);

//����������� ����������� ��������
double StandartOperator(double a, double b, char c);

//�������� �� ��������� �� � �
int CheckConst(string s);

//�������� �� �������
int Func(string s);

//�������� �������
bool CheckFunc(string s, string fun, int &i);

//���������� ��������� �������
double DuFunc(string fun, double a);
double DuFunc(string fun, double a, double b);

//�������� �� ������
bool Eror(char c, MyStack<string>& stack);

class calculator {
	string formula;
	string postfix;
	map<string, double> var;
	//��������� ��������
	int priority(char c);
public:
	calculator();
	calculator(string formula);
	//�������� �������
	string GetFormula();
	//�������� ����������� ������
	string GetPostfix();
	//������� �������
	void SetFormula(string formula);
	//�������������� ������� � ����������� ������
	void FormulaConverrt();
	//�������� �����
	double Ansver();
	//�������� ������ ����������
	map<string, double> GetVar() { return var; }
	//������� ������ ����������
	void SetVar(map<string,double> var);
	
};
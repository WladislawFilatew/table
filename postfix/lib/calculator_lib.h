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

//Удаление пробелов
string RemoveSpace(string s);

//Удаление не нужных нулей
string Remove0(string s);

//Проверка на коректность введенной формулы
bool CheckFormula(string s);

//Приведение к числу с i индекса
double ToDouble(string s, int& i);

//Приведение к строковой переменной с i индекса
string ToStringVar(string s, int& i);

//Проверка на число
bool CheckNumber(char c);

//Проверка на символ
bool CheckChar(char c);

//Проверка на базовые операции
bool CheckOperator(char c);
bool CheckOperator(string s);

//Выаполнение стандартных операций
double StandartOperator(double a, double b, char c);

//Проверка на константы Пи и Е
int CheckConst(string s);

//Проверка на функции
int Func(string s);

//Проверка функции
bool CheckFunc(string s, string fun, int &i);

//Вычисления выражения функций
double DuFunc(string fun, double a);
double DuFunc(string fun, double a, double b);

//Проверка на ошибку
bool Eror(char c, MyStack<string>& stack);

class calculator {
	string formula;
	string postfix;
	map<string, double> var;
	//Приоритет операций
	int priority(char c);
public:
	calculator();
	calculator(string formula);
	//Получить формулу
	string GetFormula();
	//Получить постфиксную запись
	string GetPostfix();
	//Задание формулы
	void SetFormula(string formula);
	//Преобразование формулы в постфиксную запись
	void FormulaConverrt();
	//Получить ответ
	double Ansver();
	//Получить список переменных
	map<string, double> GetVar() { return var; }
	//Вернуть список переменных
	void SetVar(map<string,double> var);
	
};
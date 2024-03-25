#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "..\stack\stacklib\stacklib.h"
#include "func.h"
using namespace std;

namespace postfix {

	/*
	* Выполнил: Филатьев В.
	* Библиотека для преобразования выражения в постфиксную форму и поиска ответа,
	* также возможно вычислить выражения с переменными
	*/

	const double PI = 3.141592653589793; ///<Число пи
	const double E = 2.718281828459045; ///<Число е

	//Удаление пробелов
	/*!
	* Функция удаления пробелов из строки
	* \param[out] выходной параметр string, выражение с пробелами
	* \param[in] входной параметр string, выражение без пробелов
	*/
	string RemoveSpace(string s);

	/*!
	* Функция удаление не нужных нулей
	* \param[out] выходной параметр string, выражение с нулями после запятой
	* \param[in] входной параметр string, выражение без нулей после запятой
	*/
	string Remove0(string s);

	/*!
	* Проверка на коректность введенной формулы
	* \param[out] входной параметр string, выражение формулы
	* \param[in] выходной параметр bool, true - если формула записана верно, false - если формула ложна
	*/
	bool CheckFormula(string s);

	/*!
	* Функция приводит строку к число начиная с i индекса,
	* после выполнения в i находится символ указываюший на конец числа в строке
	* \param[out] выходной параметр string, формула
	* \param[out] выходной параметр int, индекс первого символа числа в строке
	* \param[in] выходной параметр double, полученное число
	*/
	double ToDouble(string s, int& i);

	/*!
	* Функция приводит строку к строковой переменной начиная с i индекса,
	* после выполнения в i находится символ указываюший на конец числа в строке
	* \param[out] выходной параметр string, формула
	* \param[out] выходной параметр int, индекс первого символа строковой переменной в строке
	* \param[in] выходной параметр string, полученное имя переменной
	*/
	string ToStringVar(string s, int& i);

	/*!
	* Функция проверяет символ типа char является ли он числом
	* \param[out] выходной параметр char, входной символ
	* \param[in] выходной параметр bool,true - если число, false - если не число
	*/
	bool CheckNumber(char c);

	/*!
	* Функция проверяет символ типа char является ли буквиным символом
	* \param[out] выходной параметр char, входной символ
	* \param[in] выходной параметр bool,true - если буквиный символ, false - если не буквиный символ
	*/
	bool CheckChar(char c);


	/*!
	* Функция проверяет символ типа char на принадлежность базовым операциям,
	* такие как *,-,+,...
	* \param[out] выходной параметр char, входной символ
	* \param[in] выходной параметр bool,true - если базовая операция, false - если не базовая операция
	*/
	bool CheckOperator(char c);

	/*!
	* Функция проверяет символ типа string на принадлежность базовым операциям,
	* такие как *,-,+,...
	* \param[out] выходной параметр char, входной символ
	* \param[in] выходной параметр bool,true - если базовая операция, false - если не базовая операция
	*/
	bool CheckOperator(string s);

	/*!
	* Функция выополняет стандартные операции и возврашает результат его
	* \param[out] входной параметр double a - первый аргумент
	* \param[out] входной параметр double b - второй аргумент
	* \param[out] входной параметр char c - стандартная операция
	* \param[in] выходной параметры double - результат выполнения операции
	*/
	double StandartOperator(double a, double b, char c);

	/*!
	* Функция проверки на константы Пи и е
	* \param[out] входной параметр string - строка выражения
	* \param[in] выходной параметры int - 1 если это е, 2 если Пи и 0 если что то другое
	*/
	int CheckConst(string s);

	/*!
	* Функция проверки на встроеенные функции в класс
	* \param[out] входной параметр string - строка выражения
	* \param[in] выходной параметры int - 1 или 2 количестово параметров для функции, 0 если функция не втроенна
	*/
	int Func(string s);

	//Проверка функции
	/*!
	* Рекурсивная проверка функции на верность введенной формулы с i индекса,
	* после выполнения в i находится символ указываюший на конец числа в строке
	* \param[out] входной параметр string - строка выражения
	* \param[out] входной параметр string - строка функции
	* \param[out] входной параметр int - индекс первого символа числа в строке
	* \param[in] выходной параметры bool - true если выражение верно записано
	*/
	bool CheckFunc(string s, string fun, int& i);

	/*!
	* Вычисление выражение функции
	* \param[out] входной параметр string - строкове представление функции
	* \param[out] входной параметр double - аргумент для функции
	* \param[in] выходной параметры double - результат работы функции
	*/
	double DuFunc(string fun, double a);

	/*!
	* Вычисление выражение функции
	* \param[out] входной параметр string - строкове представление функции
	* \param[out] входной параметр double a - перввый аргумент функции
	* \param[out] входной параметр double b - второй аргумент функции
	* \param[in] выходной параметры double - результат работы функции
	*/
	double DuFunc(string fun, double a, double b);

	/*!
	* Функция проверки на ошибки в записи формулы
	* \param[out] входной параметр char - оператор для которогу нужно проверить верность аргументов
	* \param[out] входной параметр stak - параметры введенные в стек
	* \param[in] выходной параметры bool - результат проверки
	*/
	bool Eror(char c, MyStack<string>& stack);


	/*
	* Класс для вычисления выражения с помошью метода постфиксной записи
	*/
	class calculator {
		string formula; ///<Исходная формула
		string postfix; ///<Постфиксный вид формулы
		map<string, double> var; ///Словарь для хранения значений переменных
		/*!
		* Метод, который выводит приотритет операциям
		* \param[out] входной параметр char - опирация
		* \param[in] выходной параметры int - приоритет данной операции
		*/
		int priority(char c);
	public:
		/*!
		* Конструктор по умолчанию
		*/
		calculator();
		/*!
		* Конструктор иницилазации
		* \param[out] входной параметр string - исходная формула
		*/
		calculator(string formula);
		/*!
		* Функция возрашает исходную формулу
		* \param[in] выходной параметр string - возврашает исходную формулу
		*/
		string GetFormula();
		/*!
		* Функция возрашает постфиксную запись формулы
		* \param[in] выходной параметр string - возврашает постфиксную формулу
		*/
		string GetPostfix();
		/*!
		* Функция задает формулу
		* \param[out] выходной параметр string - исходная формула
		*/
		void SetFormula(string formula);
		/*!
		* Функция перевода исходной формулы в постфиксную форму
		*/
		void FormulaConverrt();
		/*!
		* Функция возврашает ответ на введенную формулу
		* \param[out] выходной параметр double - ответ
		*/
		double Ansver();
		/*!
		* Функция возврашает словарь на параметы
		* \param[out] выходной параметр map - список параметров
		*/
		map<string, double> GetVar() { return var; }
		/*!
		* Функция задает параметрам переменных значение
		* \param[in] входной параметр map - список параметров
		*/
		void SetVar(map<string, double> var);

	};






	bool CheckNumber(char c)
	{
		return (c >= '0' && c <= '9' || c == '.');
	}

	bool CheckChar(char c) {
		return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_');
	}

	bool CheckOperator(char c)
	{
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
	}
	bool CheckOperator(string s)
	{
		return CheckOperator(s[0]);
	}

	int CheckConst(string s) {
		if (s == "E" || s == "e")
			return 1;
		else if (s == "PI" || s == "pi" || s == "Pi")
		{
			return 2;
		}
		return 0;
	}

	int Func(string s)
	{
		if (s == "sin" || s == "cos" || s == "tg" || s == "ctg" || s == "ln")
			return 1;
		if (s == "pow" || s == "sqrt" || s == "log" || s == "A" || s == "C")
			return 2;
		return 0;
	}

	bool CheckFunc(string s, string func, int& i)
	{
		int kol = 1;
		int zap = 0, ti = i + 1;
		i += 2;
		string temp = "(", temp2 = "(";
		while (i < s.size() && kol != 0) {
			switch (s[i])
			{
			case '(':
				kol += 1;
				break;
			case ')':
				kol -= 1;
				break;
			case ',':
				if (zap == 0 && kol == 1) {
					zap = 1;
					temp += ')';
				}
			default:
				break;
			}
			if (zap == 0)
				temp += s[i];
			else if (zap == 2) {
				temp2 += s[i];
			}
			else
				zap = 2;
			i++;
		}
		i--;
		if (Func(func) == 1) {
			if (zap != 0)
				return false;
			return CheckFormula(temp);
		}
		if (Func(func) == 2) {
			if (zap == 0)
				return false;
			return CheckFormula(temp) && CheckFormula(temp2);
		}
		return true;
	}

	double DuFunc(string fun, double a)
	{
		if (fun == "sin")
			return sin(a);
		if (fun == "cos")
			return cos(a);
		if (fun == "tg")
			return sin(a) / cos(a);
		if (fun == "ctg")
			return cos(a) / sin(a);
		if (fun == "ln")
			return log(a);
		return 0.0;
	}

	double DuFunc(string fun, double a, double b)
	{
		if (fun == "pow")
			return pow(a, b);
		if (fun == "sqrt")
			return pow(a, (1 / b));
		if (fun == "log")
			return Log(b, a);
		if (fun == "A")
			return A(a, b);
		if (fun == "C")
			return C(a, b);
		return 0.0;
	}



	double StandartOperator(double a, double b, char c)
	{
		switch (c)
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '%':
			return (int)a % (int)b;
		case '^':
			return pow(a, b);
		default:
			return 0;
		}
	}

	string RemoveSpace(string s)
	{
		int i = 0;
		while (i < s.size()) {
			if (s[i] == ' ')
				s.erase(i, 1);
			else
				i++;
		}
		return s;
	}

	string Remove0(string s) {
		int i = s.size() - 1;
		while (i >= 0 && s[i] == '0') {
			s.pop_back();
			i--;
		}
		if (s.back() == '.')
			s.pop_back();
		return s;

	}

	double ToDouble(string s, int& i) {
		double k = 0;
		int kol = 0;
		while (s[i] != '\0' && CheckNumber(s[i])) {
			if (s[i] != '.')
				k = k * 10 + (s[i] - 48);
			if (s[i] == '.' || kol != 0)
				kol++;
			i++;
		}
		i--;
		return k / pow(10, ((kol == 0) ? 0 : kol - 1));
	}

	string ToStringVar(string s, int& i) {
		string temp;
		char c = s[i];
		while (c != '\0' && CheckChar(c)) {
			temp += s[i];
			i++;
			c = s[i];
		}
		i--;
		return temp;
	}

	bool Eror(char c, MyStack<string>& stack)
	{
		bool flag = true;
		switch (c)
		{
		case '(':
			if (!stack.empty() && stack.top() == "!")
				flag = false;
			break;
		case '~':
			if (stack.empty() || stack.top() != "(" || stack.top() == "!")
				flag = false;
			break;
		case ')':
			if (stack.size() < 2 || !(stack.top() == "P" || stack.top() == "SK" || CheckNumber(stack.top()[0]) || CheckChar(stack.top()[0])))
				flag = false;
			break;
		case '+':
			if (stack.empty() || stack.top() == "(" || CheckOperator(stack.top()) || stack.top() == "~")
				flag = false;
			break;
		case '!':
			if (stack.empty() || stack.top() == "+" || stack.top() == "(" || stack.top() == "~")
				flag = false;
			break;
		default:
			if (!stack.empty() && stack.top() == "!")
				flag = false;
			break;
		}
		return flag;
	}

	bool CheckFormula(string s)
	{
		s = RemoveSpace(s);
		MyStack<string>stack;
		int i = 0;
		while (i < s.size()) {
			char c = (CheckOperator(s[i]) ? '+' : s[i]);

			if (!Eror(c, stack))
				return false;

			switch (c) {
			case '!':
				stack.pop();
				stack.push("P");
				break;
			case '~':
				stack.push("~");
				break;
			case '(':
				stack.push("(");
				break;
			case ')':
				stack.pop(); stack.pop();
				if (stack.empty() || stack.top() == "(")
					stack.push("SK");
				else if (CheckOperator(stack.top())) {
					stack.pop();
					stack.push("P");
				}
				else
					return false;
				break;

			case '+':

				stack.pop();
				stack.push(string(1, s[i]));
				break;

			default:
				string var;
				if (CheckNumber(c)) {
					double num = ToDouble(s, i);
					var = to_string(num);
				}
				if (c != '\0' && CheckChar(c)) {
					var = ToStringVar(s, i);
				}

				if (Func(var)) {
					if (!CheckFunc(s, var, i))
						return false;
					var = "SK";
				}


				if (stack.top() == "(")
					stack.push(var);
				else if (CheckOperator(stack.top())) {
					stack.pop();
					stack.push("P");
				}
				else if (stack.top() == "~") {
					stack.pop();
					stack.push("P");
				}
				else
					return false;
			}
			i++;
		}
		if (stack.top() != "SK" || stack.size() != 1)
			return false;
		return true;
	}




	int calculator::priority(char c)
	{
		switch (c)
		{
		case '(':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/': case '%':
			return 2;
		case '^':
			return 3;
		case '~':
			return 4;
		default:
			return -1;
		}
	}

	calculator::calculator()
	{
		this->formula = "";
		this->postfix = "";
	}

	calculator::calculator(string formula)
	{
		SetFormula(formula);
	}

	void calculator::SetFormula(string formula)
	{
		formula = RemoveSpace("(" + formula + ")");
		//Замена унарного минуса на ~
		size_t start{ formula.find("(-") };
		while (start != std::string::npos)
		{
			formula.replace(start, 2, "(~");
			start = formula.find("(-", start + 2);
		}

		postfix.clear();
		if (!CheckFormula(formula))
			throw exception("Введено неверная формула");
		this->formula = formula;
		this->FormulaConverrt();
	}

	string calculator::GetFormula()
	{
		string temp;
		for (auto a : formula) {
			if (CheckOperator(a))
				temp = temp + " " + a + " ";
			else if (a == '~')
				temp += '-';
			else
				temp += a;
		}
		return temp;
	}

	string calculator::GetPostfix()
	{
		string temp = postfix;
		for (char& a : temp) {
			if (a == '~')
				a = '-';
		}
		return temp;
	}

	void calculator::FormulaConverrt()
	{
		var.clear();
		if (formula.empty())
			throw exception("Формула не заданна");
		MyStack<string> stack;
		int i = 0;
		while (i < formula.size()) {
			char c = (CheckOperator(formula[i]) ? '+' : formula[i]);
			switch (c)
			{
			case '(':
				stack.push("(");
				break;
			case ')':
				while (stack.top() != "(") {
					if (!postfix.empty() && postfix.back() != ' ')
						postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				stack.pop();
				if (!stack.empty() && Func(stack.top())) {
					if (!postfix.empty() && postfix.back() != ' ')
						postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				if (!postfix.empty() && postfix.back() != ' ')
					postfix += " ";
				break;
			case ',':
				while (stack.top() != "(") {
					if (!postfix.empty() && postfix.back() != ' ')
						postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				if (!postfix.empty() && postfix.back() != ' ')
					postfix += " ";
				break;
			case '+': case '~':
				while (CheckOperator(stack.top()) && priority(formula[i]) <= priority(stack.top()[0])) {
					if (!postfix.empty() && postfix.back() != ' ')
						postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				stack.push(string(1, formula[i]));
				if (!postfix.empty() && postfix.back() != ' ')
					postfix += " ";
				break;

			default:
				if (CheckChar(c)) {
					string temp = ToStringVar(formula, i);
					if (Func(temp))
						stack.push(temp);
					else {
						if (!CheckConst(temp))
							var.insert({ temp,0 });
						postfix += temp;
					}
				}
				else if (CheckNumber(c)) {
					int num = ToDouble(formula, i);
					postfix += Remove0(to_string(num));
				}
				else
					postfix += c;
				if (!postfix.empty() && postfix.back() != ' ')
					postfix += " ";
			}
			i++;

		}
	}

	double calculator::Ansver()
	{
		MyStack<double> stack;
		double a, b;
		int i = 0;
		while (i < postfix.size()) {
			char c = (CheckOperator(postfix[i]) ? '+' : postfix[i]);
			switch (c)
			{
			case '~':
				a = stack.top(); stack.pop();
				stack.push(-a);
				break;
			case '+':
				a = stack.top(); stack.pop();
				b = stack.top(); stack.pop();
				stack.push(StandartOperator(b, a, postfix[i]));
				break;
			case ' ':
				break;
			default:
				if (c == '!') {
					int n = (int)stack.top(); stack.pop();
					stack.push(fac(n));
					break;
				}
				if (CheckNumber(postfix[i]))
					stack.push(ToDouble(postfix, i));
				else {
					string temp = ToStringVar(postfix, i);
					if (!Func(temp)) {
						if (CheckConst(temp) == 0)
							stack.push(var.at(temp));
						else if (CheckConst(temp) == 1)
							stack.push(E);
						else
							stack.push(PI);
					}
					else {
						if (Func(temp) == 1) {
							double a = stack.top(); stack.pop();
							stack.push(DuFunc(temp, a));
						}
						if (Func(temp) == 2) {
							double a = stack.top(); stack.pop();
							double b = stack.top(); stack.pop();
							stack.push(DuFunc(temp, b, a));
						}
					}
				}
			}
			i++;
		}
		return stack.top();
	}

	void calculator::SetVar(map<string, double> var)
	{
		for (auto a : var) {
			this->var[a.first] = a.second;
		}
	}

}
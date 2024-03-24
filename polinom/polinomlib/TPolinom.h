#pragma once
#include "TList.h"
#include "TMonom.h"
#include <string>

/*!
* Выполнил: Филатьев В.
*/

const int nonDisplayedZeros = 4; ///< Количество неотображаемых нулей при выводе коэффициента полинома

/*!
* Функция удаления пробелов из строки
* \param[in] входной параметр string - строка с пробелами
* \param[out] выходной параметр string - строка без пробелов
*/
string RemoveSpace(string s);


/*!
* Выполнил: Филатьев В.
* Класс полином: работает на списке мономов
*/
class TPolinom
{
public:
	List<TMonom> list; ///< Список мономов, список двухнаправленный 

	/*!
	* Конструктор копирования
	*  \param[in] входной параметр &TPolinom - ссылка на полином
	*/
	TPolinom(TPolinom& other);

	/*!
	* Конструктор копирования
	*/
	TPolinom() {};

	/*!
	* Конструктор копирования
	*  \param[in] входной параметр string - строковое представление полинома
	*/
	TPolinom(string str);

	/*!
	* Оператор присваивания
	*/
	TPolinom& operator=(TPolinom& other);

	/*!
	* Оператор сложения полиномов
	*/
	TPolinom operator+(TPolinom& q);

	/*!
	* Оператор вычитания полиномов
	*/
	TPolinom operator-(TPolinom& q);

	/*!
	* Метод изменения полинома по входной строке
	*  \param[in] входной параметр string - строковое представление полинома
	*/
	void setPolinom(string s);

	/*!
	* Оператор сложение с мономом
	*/
	void operator+(TMonom newMonom);

	/*!
	* Оператор умножение на моном
	*/
	TPolinom operator*(TMonom monom);

	/*!
	* Оператор умножение на число
	*/
	TPolinom operator*(double coef);

	/*!
	* Оператор уможения полиномов
	*/
	TPolinom operator* (TPolinom& other);

	/*!
	* Оператор сравнения полиномов
	*/
	bool operator==(TPolinom& other);

	/*!
	* Метод преобразования полинома в строковый вид
	* \param[out] входной параметр string - строковое представление полинома
	*/
	string ToString(); // перевод в строку

	/*!
	* Метод вывода полинома в консоль
	*/
	friend ostream& operator<<(ostream& os, TPolinom& polinom)
	{
		cout << polinom.ToString() << endl;
		return os;
	}


	/*!
	* Производная полинома
	*/
	TPolinom derivative(char c);

	/*!
	* Интеграл полинома
	*/
	TPolinom Integral(char c);


	/*!
	* Оператор деления на моном
	*/
	TPolinom operator/(TMonom monom);

	/*!
	* Оператор деление на число
	*/
	TPolinom operator/(double coef);

	/*!
	* Оператор деления полиномов
	*/
	TPolinom operator/(TPolinom& other);

	string ToPostfix();

};

void TPolinom::setPolinom(string s) {
	list.clear();
	s = RemoveSpace(s);
	string temp;
	int i = 0;
	while (i < s.size()) {
		if (s[i] == '+') {
			this->operator+(TMonom(temp));
			temp.clear();
		}
		else if (s[i] == '-') {
			if (!temp.empty())
				this->operator+(TMonom(temp));
			temp.clear();
			temp.push_back('-');
		}
		else {
			temp += s[i];
		}
		i++;
	}
	if (!temp.empty()) {
		this->operator+(TMonom(temp));
	}
}

TPolinom::TPolinom(TPolinom& other)
{
	this->list = other.list;
}

TPolinom::TPolinom(string str)
{
	setPolinom(str);
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	this->list = other.list;
	return *this;
}

void TPolinom::operator+(TMonom m)
{
	List<TMonom>::iterator it;
	it = list.begin();
	bool flag = true;
	while (it != list.end()) {
		if (m > *it)
			break;
		if (*it == m) {
			(*it).coef += m.coef;
			flag = false;
			break;
		}
		it++;
	}
	if (!flag && (*it).coef == 0)
		list.erase(it);
	if (flag && m.coef != 0)
		list.insert(m, it);
}


TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom temp = *this;
	List<TMonom>::iterator it;
	it = other.list.begin();
	while (it != other.list.end()) {
		temp.operator+(*it);
		it++;
	}

	return temp;
}

inline TPolinom TPolinom::operator-(TPolinom& q)
{
	TPolinom temp = q * (-1);
	return (*this) + temp;
}


TPolinom TPolinom::operator*(TMonom monom)
{
	TPolinom temp = *this;
	List<TMonom>::iterator it;
	it = temp.list.begin();
	while (it != temp.list.end()) {
		(*it) = (*it).operator*(monom);
		it++;
	}

	return temp;
}

TPolinom TPolinom::operator*(double coef)
{
	List<TMonom>::iterator it;
	it = list.begin();
	while (it != list.end()) {
		(*it).coef *= coef;
		it++;
	}
	return *this;
}

TPolinom TPolinom::operator*(TPolinom& other)
{
	TPolinom temp;
	List<TMonom>::iterator it;
	it = other.list.begin();
	while (it != other.list.end()) {
		TPolinom t = this->operator*(*it);
		temp = temp + t;
		it++;
	}
	*this = temp;
	return *this;
}

bool TPolinom::operator==(TPolinom& other)
{
	return this->list == other.list;
}


string TPolinom::ToString()
{
	string result;
	List<TMonom>::iterator it;
	it = list.begin();
	while (it != list.end()) {
		if ((*it).index == 0 && (int)(*it).coef ==  1) {
			result += to_string(abs((int)(*it).coef));
		}
		if (abs((*it).coef) != 1){
			result +=  std::to_string(abs((int)(*it).coef));
		}
		if ((*it).index / 100 != 0) {
			result += "x";
			if((*it).index / 100 != 1)
				result += "^" + std::to_string((*it).index / 100);
		}
		if ((*it).index % 100 / 10 != 0) {
			result += "y";
			if((*it).index % 100 / 10 != 1)
				result += "^" + std::to_string((*it).index % 100 / 10);
		}
		if ((*it).index % 10 != 0) {
			result += "z";
			if ((*it).index % 10 != 1)
				result += "^" + std::to_string((*it).index % 10);
		}
		it++;
		if (it != list.end()) {
			if ((*it).coef < 0)
				result += " - ";
			else
				result += " + ";
		}
	}
	return result;
}

inline TPolinom TPolinom::derivative(char c)
{
	TPolinom temp = *this;
	List<TMonom>::iterator it;
	it = temp.list.begin();
	while (it != temp.list.end()) {
		(*it) = (*it).derivative(c);
		it++;
	}

	return temp;
}

inline TPolinom TPolinom::Integral(char c)
{
	TPolinom temp = *this;
	List<TMonom>::iterator it;
	it = temp.list.begin();
	while (it != temp.list.end()) {
		(*it) = (*it).Integral(c);
		it++;
	}

	return temp;
}

inline TPolinom TPolinom::operator/(TMonom monom)
{
	List<TMonom>::iterator it;
	it = list.begin();
	while (it != list.end()) {
		(*it) = (*it) / monom;
		it++;
	}
	return *this;
}

inline TPolinom TPolinom::operator/(double coef)
{
	List<TMonom>::iterator it;
	it = list.begin();
	while (it != list.end()) {
		(*it).coef /= coef;
		it++;
	}
	return *this;
}

inline TPolinom TPolinom::operator/(TPolinom& other)
{
	if (other.list.Size() > 1)
		throw exception("eror");

	*this = *this / other.list[0];
	return *this;
}

inline string TPolinom::ToPostfix()
{
	string result;
	List<TMonom>::iterator it;
	it = list.begin();
	while (it != list.end()) {
		if ((*it).index == 0 && (int)(*it).coef == 1) {
			result += to_string(abs((int)(*it).coef));
		}
		if (abs((*it).coef) != 1) {
			result += std::to_string(abs((int)(*it).coef)) + "*";
		}
		if ((*it).index / 100 != 0) {
			result += "x";
			if ((*it).index / 100 != 1)
				result += "^" + std::to_string((*it).index / 100);
			result += "*";
		}
		if ((*it).index % 100 / 10 != 0) {
			result += "y";
			if ((*it).index % 100 / 10 != 1)
				result += "^" + std::to_string((*it).index % 100 / 10);
			result += "*";
		}
		if ((*it).index % 10 != 0) {
			result += "z";
			if ((*it).index % 10 != 1)
				result += "^" + std::to_string((*it).index % 10);
		}
		if (result[result.size() - 1] == '*')
			result.pop_back();
		it++;
		if (it != list.end()) {
			if ((*it).coef < 0)
				result += " - ";
			else
				result += " + ";
		}
	}
	return result;
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

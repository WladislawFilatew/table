#pragma once
#include <string>
#include <stack>
using namespace std;

/*!
* Выполнил: Филатьев В.
*/


/*!
* Функция проверки символа на число
* \param[in] входной параметр char - символ
* \param[out] выходной параметр bool - является ли символ числом
*/
bool CheckNumber(char c)
{
	return (c >= '0' && c <= '9' || c == '.');
}

/*!
* Функция проверки символа на строковый символ
* \param[in] входной параметр char - символ
* \param[out] выходной параметр bool - является ли символ чстроковым символом
*/
bool CheckChar(char c) {
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_');
}

/*!
* Функция проверки символа на -
* \param[in] входной параметр char - символ
* \param[out] выходной параметр bool - является ли символ -
*/
bool CheckRes(char c) {
	return c == '-';
}

/*!
* Функция прреобразует строку с некоторого индекса к числу
* \param[in] входной параметр string - строка которую нужно преобразовать
* \param[in] входной параметр int - индекс символа с которого выполняется преобразоваания после работы указывает на конец числа в строке
* \param[out] выходной параметр double - полученное число
*/
double ToDouble(string s, int& i);

/*!
* Функция прреобразует строку с некоторого индекса к строковой переменной
* \param[in] входной параметр string - строка которую нужно преобразовать
* \param[in] входной параметр int - индекс символа с которого выполняется преобразоваания после работы указывает на конец переменной в строке
* \param[out] выходной параметр string - полученное имя переменной
*/
string ToStringVar(string s, int& i);


/*!
* Выполнил: Филатьев В.
* Класс моном - представляет из себя коэфиценты некоторого одночлена, с удобной работай и при этом хранимого в маленьком объеме памяти
*/
struct TMonom
{
	double coef; ///< Коэффициент монома
	int index; ///< Индекс (свертка степеней) (x00  + y0 + z)

	/*!
	* Конструктор
	*/
	TMonom();

	/*!
	* Конструктор иницилизации строки
	* \param[in] входной параметр string - строковое представление полинома (xyz или xy)
	*/
	TMonom(string s);

	/*!
	* Конструктор иницилизации
	* \param[in] входной параметр double coef - коэфицент, который стоит перед мономом
	* \param[in] входной параметр int degX, degY, degZ - степени у x,y,z соответственно
	*/
	TMonom(double coef, int degX = 0, int degY = 0, int degZ = 0);

	/*!
	* Метод установки коэфицента монома
	* \param[in] входной параметр int coef - коэфицент, который стоит перед мономом
	*/
	void SetCoef(int cval) { coef = cval; }

	/*!
	* Метод получения коэфицента монома
	* \param[out] выходной параметр int coef - коэфицент, который стоит перед мономом
	*/
	int GetCoef(void) { return coef; }

	/*!
	* Метод установки свернутой записи степеней монома
	* \param[in] входной параметр int index - сттепени монома
	*/
	void SetIndex(int ival) { index = ival; }

	/*!
	* Метод получения свернутой записи степеней монома
	* \param[out] выходной параметр int index - сттепени монома
	*/
	int GetIndex(void) { return index; }

	/*!
	* Оператор сравнения двух мономов
	*/
	bool operator==(const TMonom& other) {return  this->index == other.index; }

	/*!
	* Оператор сравнения двух мономов
	*/
	bool operator>(const TMonom& other);

	/*!
	* Оператор сравнения двух мономов
	*/
	bool operator<(const TMonom& other) {return  !(this->operator>(other) && this->operator==(other));}

	/*!
	* Оператор умножения монома на моном
	*/
	TMonom& operator*(const TMonom& other);
};



TMonom::TMonom()
{
	this->coef = 1;
	this->index = 0;
}

TMonom::TMonom(string s) :TMonom()
{
	stack<string> st;
	int i = 0;
	while (i < s.size()) {
		if (CheckRes(s[i])) {
			st.push("-");
		}
		else if (CheckNumber(s[i])) {
			double temp = ToDouble(s, i);
			if (st.empty())
				coef = temp;
			else if (st.top() == "-") {
				coef = -temp;
				st.pop();
			}
			else if (st.top() == "^") {
				st.pop();
				if (st.top() == "x" || st.top() == "X")
					index += 100 * temp;
				if (st.top() == "y" || st.top() == "Y")
					index += 10 * temp;
				if (st.top() == "z" || st.top() == "Z")
					index += temp;
				st.pop();
			}

		}
		else if (CheckChar(s[i])) {
			string var; var += s[i];
			if (st.empty())
				st.push(var);
			else if (st.top() == "-") {
				coef = -1;
				st.pop();
				st.push(var);
			}
			else {
				if (st.top() == "x" || st.top() == "X")
					index += 100;
				if (st.top() == "y" || st.top() == "Y")
					index += 10;
				if (st.top() == "z" || st.top() == "Z")
					index += 1;
				st.pop();
				st.push(var);
			}
		}
		else if (s[i] == '^') {
			st.push("^");
		}
		i++;
	}
	if (!st.empty()) {
		if (st.top() == "x" || st.top() == "X")
			index += 100;
		if (st.top() == "y" || st.top() == "Y")
			index += 10;
		if (st.top() == "z" || st.top() == "Z")
			index += 1;
		st.pop();
	}
}

inline TMonom::TMonom(double coef, int degX, int degY, int degZ)
{
	if (degX > 9 || degY > 9 || degZ > 9)
		throw exception("deg > 9");
	this->coef = coef;
	this->index = 100 * degX + 10 * degY + degZ;
}

inline bool TMonom::operator>(const TMonom& other)
{
	if (this->index / 100 == other.index / 100) {
		if ((this->index % 100) / 10 == (other.index % 100) / 10) {
			if (this->index % 10 == other.index % 10) {
				return false;
			}
			else
				return this->index % 10 > other.index % 10;
		}
		else
			return (this->index % 100) / 10 > (other.index % 100) / 10;
	}
	else
		return this->index / 100 > other.index / 100;
}

inline TMonom& TMonom::operator*(const TMonom& other)
{
	if (this->index / 100 + other.index / 100 > 9)
		throw exception("of range");
	if ((this->index % 100) / 10 + (other.index % 100) / 10 > 9)
		throw exception("of range");
	if (this->index % 10 + other.index % 10 > 9)
		throw exception("of range");
	TMonom temp;
	temp.index = this->index + other.index;
	temp.coef = this->coef * other.coef;
	return temp;
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
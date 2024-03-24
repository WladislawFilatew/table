#include <iostream>
#include "table.h"
#include "maneger.h"
#include "postfix.h"
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

int vibor(int kol);
int nowvibor(int kol);


int main() {

	maneger men;

	/*men.Insert("1", TPolinom("x + y"));
	men.Insert("2", TPolinom("y + 4"));
	men.Insert("3", *men.Find("1") + *men.Find("2"));

	men.ChooseTable("Tree");*/

	//cout << table->Count();

	//cout << men.Find("3")->ToPostfix();




	setlocale(LC_ALL, "ru");
	int wibor;
	int nowwibor;
	TPolinom polinom;
	do {
		system("cls");
		cout << "\tМеню:\n1)Операции над отдельными полиномами\n2)Операции в выражениях из полиномов\n3)Операции над таблицами\n4)Выбор таблиц\n";
		wibor = vibor(5);
		system("cls");
		if (wibor == 1) {

			system("cls");
			cout << "\tМеню:\n1)Вычисление в точке\n2)Умножение на константу\n3)Производная\n4)Интеграл\n";
			nowwibor = nowvibor(5);
			system("cls");
			if (nowwibor == 1) {
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				postfix::calculator a((*men.Find(k)).ToPostfix());
				auto var = a.GetVar();
				for (auto& a : var) {
					cout << a.first << " = ";
					cin >> a.second;
				}
				a.SetVar(var);
				system("cls");
				cout << a.Ansver() << endl;
			}
			if (nowwibor == 2) {
				double n;
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				cout << "Введите константу:" << endl;
				cin >> n;
				polinom.operator*(n);
			}
			if (nowwibor == 3) {
				char n;
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				TPolinom polin;
				cout << "Введите по какой переменной хотите найти производную:" << endl;
				cin >> n;
				men.Insert(k + "_der", polin.derivative(n));
			}
			if (nowwibor == 4) {
				char n;
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				TPolinom polin;
				cout << "Введите по какой переменной хотите вычислить интеграл:" << endl;
				cin >> n;
				men.Insert(k + "_ins", polin.Integral(n));
			}
			while (nowwibor != 5);
		}




		if (wibor == 2)
		{

			system("cls");
			cout << "\tМеню:\n1)Сложение\n2)Вычитание\n3)Умножение на константу\n4)Умножение полиномов\n5)Деление полиномов\n";
			nowwibor = nowvibor(6);
			system("cls");
			if (nowwibor == 1) {
				cout << "Введите первый ключ:" << endl;
				string k; getline(cin, k);
				cout << "Введите второй ключ:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "+" + g, *men.Find(k) + *men.Find(g));
			}
			if (nowwibor == 2) {
				cout << "Введите первый ключ:" << endl;
				string k; getline(cin, k);
				cout << "Введите второй ключ:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "-" + g, *men.Find(k) - *men.Find(g));
			}
			if (nowwibor == 3) {
				double n;
				cout << "Введите первый ключ:" << endl;
				string k; getline(cin, k);
				cout << "Введите константу:" << endl;
				cin >> n;
				men.Insert(k + "*" + k, *men.Find(k) * n);
			}
			if (nowwibor == 4) {
				cout << "Введите ключ первого полинома:" << endl;
				string k; getline(cin, k);
				cout << "Введите ключ второго полинома:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "*" + g, *men.Find(k) * *men.Find(g));
			}
			if (nowwibor == 5) {
				cout << "Введите ключ первого полинома:" << endl;
				string k; getline(cin, k);
				cout << "Введите ключ второго полинома:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "*" + g, *men.Find(k) / *men.Find(g));
			}
			while (nowwibor != 6);
		}


		if (wibor == 3) {

			system("cls");
			cout << "\tМеню:\n1)Добавление полинома\n2)Удаление полинома\n3)Поиск\n4)Вывод активной таблицы на экран\n";
			nowwibor = nowvibor(5);
			system("cls");
			if (nowwibor == 1) {
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				cout << "Введите полином:" << endl;
				string s; getline(cin, s);
				polinom.setPolinom(s);
				men.Insert(k, s);
			}
			if (nowwibor == 2) {
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				men.Delete(k);
			}
			if (nowwibor == 3) {
				cout << "Введите ключ:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				cout << men.Find(k);
			}
			if (nowwibor == 4) {
				cout << men;
			}
			while (nowwibor != 5);
		}

		if (wibor == 4) {

			system("cls");
			cout << "\tМеню:\n1)Линейная таблица на массиве\n2)Линейная таблица на списке\n3)Упорядоченная таблица на массиве\n4)Дерево\n5)Первая хэш-таблица\n6)Вторая хэш-таблица\n";
			nowwibor = nowvibor(7);
			system("cls");
			if (nowwibor == 1) {
				men.ChooseTable("LinerOnArray");
			}
			if (nowwibor == 2) {
				men.ChooseTable("LinearOnList");
			}
			if (nowwibor == 3) {
				men.ChooseTable("OrderedOnArray");
			}
			if (nowwibor == 4) {
				men.ChooseTable("Tree");
			}
			if (nowwibor == 5) {
				men.ChooseTable("???");
			}
			if (nowwibor == 5) {
				men.ChooseTable("???");
			}
			while (nowwibor != 7);
		}

	} while (wibor != 5);
	cout << "\tНад проектом работали:\n\n1)Филатьев Владислав\n2)Соловьева Елизавета\n3)Макадрай Артем\n";
}

int vibor(int kol) {
	char a;
	do {
		a = _getch() - 48;
	} while (!(a >= 1 && a <= kol));
	return (int)a;
}
int nowvibor(int kol) {
	char a;
	do {
		a = _getch() - 48;
	} while (!(a >= 1 && a <= kol));
	return (int)a;
}


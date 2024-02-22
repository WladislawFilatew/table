#include <iostream>
#include <conio.h>
#include "TList.h"
#include "TPolinom.h"
using namespace std;

int vibor(int kol) {
	char a;
	do {
		a = _getch() - 48;
	} while (!(a >= 1 && a <= kol));
	return (int)a;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int wibor;
	TPolinom polinom;
	do {
		system("cls");
		cout << "\tМеню:\n1)Ввести полином\n2)Вывести полином\n3)Сложение\n4)Умножение\n5)Выход\n";
		wibor = vibor(5);
		system("cls");
		if (wibor == 1) {
			cout << "Введите полином:" << endl;
			string s; getline(cin, s);
			polinom.setPolinom(s);
		}
		if (wibor == 2) {
			cout << "Полином:" << endl;
			cout << polinom.ToString() << endl;
			system("pause");
		}
		if (wibor == 3) {
			cout << "Введите полином:" << endl;
			string s; getline(cin, s);
			TPolinom temp(s);
			system("cls");
			cout << "Сумма:\n";
			polinom + temp;
			cout << polinom.ToString() << endl;
			system("pause");
		}
		if (wibor == 4) {
			cout << "Введите полином:" << endl;
			string s; getline(cin, s);
			TPolinom temp(s);
			system("cls");
			cout << "Произведение:\n";
			polinom * temp;
			cout << polinom.ToString() << endl;
			system("pause");
		}


	} while (wibor != 5);


}
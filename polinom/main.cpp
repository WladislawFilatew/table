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
		cout << "\t����:\n1)������ �������\n2)������� �������\n3)��������\n4)���������\n5)�����\n";
		wibor = vibor(5);
		system("cls");
		if (wibor == 1) {
			cout << "������� �������:" << endl;
			string s; getline(cin, s);
			polinom.setPolinom(s);
		}
		if (wibor == 2) {
			cout << "�������:" << endl;
			cout << polinom.ToString() << endl;
			system("pause");
		}
		if (wibor == 3) {
			cout << "������� �������:" << endl;
			string s; getline(cin, s);
			TPolinom temp(s);
			system("cls");
			cout << "�����:\n";
			polinom + temp;
			cout << polinom.ToString() << endl;
			system("pause");
		}
		if (wibor == 4) {
			cout << "������� �������:" << endl;
			string s; getline(cin, s);
			TPolinom temp(s);
			system("cls");
			cout << "������������:\n";
			polinom * temp;
			cout << polinom.ToString() << endl;
			system("pause");
		}


	} while (wibor != 5);


}
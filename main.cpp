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

void NotKey() {
	cout << "������ ���� � ������� �� ���������" << endl;
	system("pause");
	system("cls");
}


TPolinom* GetPolinom(maneger &men, string &k = string("key")) {
	TPolinom* temp;
	do {
		cout << "������� ����:" << endl;
		getline(cin, k);
		while (k == "")
			getline(cin, k);
		temp = men.Find(k);
		if (temp == nullptr) NotKey();
	} while (temp == nullptr);
	return temp;
}


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
	do {
		system("cls");
		cout << "\t����:\n1)�������� ��� ���������� ����������\n2)�������� � ���������� �� ���������\n3)�������� ��� ���������\n4)����� ������\n";
		wibor = vibor(5);
		system("cls");
		if (wibor == 1) {

			system("cls");
			cout << "\t����:\n1)���������� � �����\n2)��������� �� ���������\n3)�����������\n4)��������\n";
			nowwibor = nowvibor(5);
			system("cls");
			if (nowwibor == 1) {
				TPolinom* temp = GetPolinom(men);
				postfix::calculator a((*temp).ToPostfix());
				auto var = a.GetVar();
				for (auto& a : var) {
					cout << a.first << " = ";
					cin >> a.second;
				}
				a.SetVar(var);
				system("cls");
				cout << a.Ansver() << endl;
				system("pause");
				nowwibor = 5;
			}
			if (nowwibor == 2) {
				int n;
				string k;
				TPolinom polinom = *GetPolinom(men, k);
				cout << "������� ���������:" << endl;
				cin >> n;
				polinom = polinom.operator*(n);
				men.Insert(k + "*" + to_string(n), polinom);
				nowwibor = 5;
			}
			if (nowwibor == 3) {
				char n; string k;
				TPolinom polin = *GetPolinom(men,k);
				cout << "������� �� ����� ���������� ������ ����� �����������:" << endl;
				cin >> n;
				men.Insert(k + "_der", polin.derivative(n));
				nowwibor = 5;
			}
			if (nowwibor == 4) {
				char n; string k;
				TPolinom polin = *GetPolinom(men, k);
				cout << "������� �� ����� ���������� ������ ��������� ��������:" << endl;
				cin >> n;
				men.Insert(k + "_ins", polin.Integral(n));
				nowwibor = 5;
			}
			while (nowwibor != 5);
		}




		if (wibor == 2)
		{

			system("cls");
			cout << "\t����:\n1)��������\n2)���������\n3)��������� �� ���������\n4)��������� ���������\n5)������� ���������\n";
			nowwibor = nowvibor(6);
			system("cls");
			if (nowwibor == 1) {
				string k; string g;
				men.Insert(k + "+" + g, *GetPolinom(men, k) + *GetPolinom(men, g));
				cout << *men.Find(k + "+" + g);
				system("pause");
				nowwibor = 6;
			}
			if (nowwibor == 2) {
				string k; string g;
				men.Insert(k + "-" + g, *GetPolinom(men, k) - *GetPolinom(men, g));
				cout << *men.Find(k + "-" + g);
				system("pause");
				nowwibor = 6;
			}
			if (nowwibor == 3) {
				double n; string k;
				TPolinom polinom = *GetPolinom(men, k);
				cout << "������� ���������:" << endl;
				cin >> n;
				polinom = polinom * n;
				men.Insert(k + "*" + to_string(n), polinom);
				cout << *men.Find(k + "*" + to_string(n));
				system("pause");
				nowwibor = 6;
			}
			if (nowwibor == 4) {
				string k; string g;
				men.Insert(k + "*" + g, *GetPolinom(men, k) * *GetPolinom(men, g));
				cout << *men.Find(k + "*" + g);
				system("pause");
				nowwibor = 6;
			}
			if (nowwibor == 5) {
				string k; string g;
				men.Insert(k + "/" + g, *GetPolinom(men, k) / *GetPolinom(men, g));
				cout << *men.Find(k + "/" + g);
				system("pause");
				nowwibor = 6;
			}
			while (nowwibor != 6);
		}


		if (wibor == 3) {

			system("cls");
			cout << "\t����:\n1)���������� ��������\n2)�������� ��������\n3)�����\n4)����� �������� ������� �� �����\n";
			nowwibor = nowvibor(5);
			system("cls");
			if (nowwibor == 1) {
				cout << "������� ����:" << endl;
				string k; getline(cin, k);
				while (k == "")
					getline(cin, k);
				cout << "������� �������:" << endl;
				string s; getline(cin, s);
				while (s == "")
					getline(cin, s);
				TPolinom polinom(s);
				men.Insert(k, polinom);
				nowwibor = 5;
			}
			if (nowwibor == 2) {
				string k;
				GetPolinom(men, k);
				men.Delete(k);
				nowwibor = 5;
			}
			if (nowwibor == 3) {
				cout << *GetPolinom(men);
				system("pause");
				nowwibor = 5;
			}
			if (nowwibor == 4) {
				cout << men;
				system("pause");
				nowwibor = 5;
			}
			while (nowwibor != 5);
		}

		if (wibor == 4) {

			system("cls");
			cout << "\t����:\n1)�������� ������� �� �������\n2)�������� ������� �� ������\n3)������������� ������� �� �������\n4)������\n5)������ ���-�������\n6)������ ���-�������\n";
			nowwibor = nowvibor(7);
			system("cls");
			if (nowwibor == 1) {
				men.ChooseTable("LinerOnArray");
				nowwibor = 7;
			}
			if (nowwibor == 2) {
				men.ChooseTable("LinearOnList");
				nowwibor = 7;
			}
			if (nowwibor == 3) {
				men.ChooseTable("OrderedOnArray");
				nowwibor = 7;
			}
			if (nowwibor == 4) {
				men.ChooseTable("Tree");
				nowwibor = 7;
			}
			if (nowwibor == 5) {
				men.ChooseTable("HashList");
				nowwibor = 7;
			}
			if (nowwibor == 6) {
				men.ChooseTable("HashChain");
				nowwibor = 7;
			}
			while (nowwibor != 7);
		}

	} while (wibor != 5);
	cout << "\t��� �������� ��������:\n\n1)�������� ���������\n2)��������� ���������\n3)�������� �����\n";
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


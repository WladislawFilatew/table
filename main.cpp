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
		cout << "\t����:\n1)�������� ��� ���������� ����������\n2)�������� � ���������� �� ���������\n3)�������� ��� ���������\n4)����� ������\n";
		wibor = vibor(5);
		system("cls");
		if (wibor == 1) {

			system("cls");
			cout << "\t����:\n1)���������� � �����\n2)��������� �� ���������\n3)�����������\n4)��������\n";
			nowwibor = nowvibor(5);
			system("cls");
			if (nowwibor == 1) {
				cout << "������� ����:" << endl;
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
				cout << "������� ����:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				cout << "������� ���������:" << endl;
				cin >> n;
				polinom.operator*(n);
			}
			if (nowwibor == 3) {
				char n;
				cout << "������� ����:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				TPolinom polin;
				cout << "������� �� ����� ���������� ������ ����� �����������:" << endl;
				cin >> n;
				men.Insert(k + "_der", polin.derivative(n));
			}
			if (nowwibor == 4) {
				char n;
				cout << "������� ����:" << endl;
				string k; getline(cin, k);
				men.Find(k);
				TPolinom polin;
				cout << "������� �� ����� ���������� ������ ��������� ��������:" << endl;
				cin >> n;
				men.Insert(k + "_ins", polin.Integral(n));
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
				cout << "������� ������ ����:" << endl;
				string k; getline(cin, k);
				cout << "������� ������ ����:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "+" + g, *men.Find(k) + *men.Find(g));
			}
			if (nowwibor == 2) {
				cout << "������� ������ ����:" << endl;
				string k; getline(cin, k);
				cout << "������� ������ ����:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "-" + g, *men.Find(k) - *men.Find(g));
			}
			if (nowwibor == 3) {
				double n;
				cout << "������� ������ ����:" << endl;
				string k; getline(cin, k);
				cout << "������� ���������:" << endl;
				cin >> n;
				men.Insert(k + "*" + k, *men.Find(k) * n);
			}
			if (nowwibor == 4) {
				cout << "������� ���� ������� ��������:" << endl;
				string k; getline(cin, k);
				cout << "������� ���� ������� ��������:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "*" + g, *men.Find(k) * *men.Find(g));
			}
			if (nowwibor == 5) {
				cout << "������� ���� ������� ��������:" << endl;
				string k; getline(cin, k);
				cout << "������� ���� ������� ��������:" << endl;
				string g; getline(cin, g);
				men.Insert(k + "*" + g, *men.Find(k) / *men.Find(g));
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
				cout << "������� �������:" << endl;
				string s; getline(cin, s);
				polinom.setPolinom(s);
				men.Insert(k, s);
			}
			if (nowwibor == 2) {
				cout << "������� ����:" << endl;
				string k; getline(cin, k);
				men.Delete(k);
			}
			if (nowwibor == 3) {
				cout << "������� ����:" << endl;
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
			cout << "\t����:\n1)�������� ������� �� �������\n2)�������� ������� �� ������\n3)������������� ������� �� �������\n4)������\n5)������ ���-�������\n6)������ ���-�������\n";
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


#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "lib/calculator_lib.h"

using namespace std;

int vibor(int kol);

int main() {
	calculator c;
	map<string, double> var;
	string formula;
	char buf;
	int v;
	try {
		do {
			system("cls");
			cout << " Menu:\n" << "1)Set formula\n" << "2)Get postfix\n" << "3)Ansver\n" << "4)Exit:\n";
			v = vibor(4);

			switch (v)
			{
			case 1:
				system("cls");
				getline(cin,formula);
				c.SetFormula(formula);
				break;
			case 2:
				system("cls");
				cout << c.GetPostfix() << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				var = c.GetVar();
				for (auto& a : var) {
					cout << a.first << " = ";
					cin >> a.second;
				}
				c.SetVar(var);
				system("cls");
				cout << c.Ansver() << endl;
				system("pause");
				getline(cin, formula);
				break;
			default:
				break;
			}
		} while (v != 4);
	}
	catch (exception & error){
		setlocale(LC_ALL, "Rus");
		cout << error.what() << endl;
	}
}



int vibor(int kol) {
	char a;
	do {
		a = _getch() - 48;
	} while (!(a >= 1 && a <= kol));
	return (int)a;
}

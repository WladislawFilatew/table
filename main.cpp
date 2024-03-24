#include <iostream>
#include "table.h"
#include "maneger.h"
#include "postfix.h"
using namespace std;


int main() {
	
	maneger men;
	


	men.Insert("1", TPolinom("x + y"));
	men.Insert("2", TPolinom("y + 4"));
	men.Insert("3", *men.Find("1") + *men.Find("2"));

	men.ChooseTable("Tree");

	//cout << table->Count();

	//cout << men.Find("3");
	

	
	postfix::calculator a((*men.Find("3")).ToPostfix());
	//cout << a.GetFormula();
	auto var = a.GetVar();
	for (auto& a : var) {
		cout << a.first << " = ";
		cin >> a.second;
	}
	a.SetVar(var);
	system("cls");
	cout << a.Ansver() << endl;
	
	
	
}

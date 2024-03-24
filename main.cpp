#include <iostream>
#include "table.h"
#include "maneger.h"
#include "postfix.h"
using namespace std;



int main() {
	
	maneger men;
	


	men.Insert("1", TPolinom("x + y"));
	men.Insert("2", TPolinom("y + 2"));
	men.Insert("3", *men.Find("1") + *men.Find("2"));

	men.ChooseTable("Tree");

	//cout << table->Count();

	//cout << men.Find("1");
	
	//calculator a((*men.Find("3")).ToString());
	//cout << a.GetFormula();
	calculator c("12 + 4");
	
}

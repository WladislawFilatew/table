#include <iostream>
#include <string>
#include "OrderedOnArray.h"
#include "table.h"
using namespace std;

/*!
* Выполнила: Соловьева Е.
*/

int main() {
	table<string, TPolinom>* table;
	OrderedOnArray<string, TPolinom> temp;
	table = &temp;


	table->Insert("1", TPolinom("x + y"));
	table->Insert("2", TPolinom("y + 2"));
	table->Insert("3", *table->Find("1") + *table->Find("2"));



	cout << *table;





}

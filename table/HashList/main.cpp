#include <iostream>
#include <string>
#include "HashList.h"
#include "table.h"
using namespace std;

/*!
* Выполнил: Макадрай А.
*/

int main() {
	table<string, TPolinom>* table;
	HashList<string, TPolinom> temp;
	table = &temp;


	table->Insert("1", TPolinom("x + y"));
	table->Insert("2", TPolinom("y + 2"));
	table->Insert("3", *table->Find("1") + *table->Find("2"));


	table->Delete("4");



	cout << *table;





}
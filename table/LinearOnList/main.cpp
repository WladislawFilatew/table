#include <iostream>
#include <string>
#include "LinearOnList.h"
#include "table.h"
using namespace std;



int main() {
	table<string, TPolinom>* table;
	LinerOnList<string, TPolinom> temp;
	table = &temp;



	table->Insert("1", TPolinom("x + y"));
	table->Insert("2", TPolinom("y + 2"));
	table->Insert("3", *table->Find("1") + *table->Find("2"));

	

	cout << *table;

	



}
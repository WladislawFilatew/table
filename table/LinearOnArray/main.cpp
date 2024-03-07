#include <iostream>
#include <string>
#include "LinearOnArray.h"
#include "table.h"
using namespace std;


int main() {
	table<string, TPolinom>* table;
	LinerOnArray<string, TPolinom> temp;
	table = &temp;



	table->Insert("1", TPolinom("x + y"));
	table->Insert("2", TPolinom("y + 2"));
	table->Insert("3", *table->Find("1") + *table->Find("2"));

	//cout << table->Count();

	cout << *table;

	/*vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);


	vector<int>::iterator b;

	b = a.begin();
	while (b != a.end()) {
		cout << *b;
		b++;
	}*/

	


}
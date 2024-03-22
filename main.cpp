#include <iostream>
#include "table.h"
#include "LinearOnArray.h"
#include <map>
using namespace std;



int main() {
	map<string,table<string,TPolinom>*> temp;
	
	temp.emplace("LinerOnArray", new LinerOnArray<string, TPolinom>);
	temp["LinerOnArray"]->Insert("1", TPolinom("x + y"));
	temp["LinerOnArray"]->Insert("2", TPolinom("y + 2"));
	cout << *temp["LinerOnArray"]->Find("1");
}

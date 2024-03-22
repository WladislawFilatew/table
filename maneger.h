#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "table.h"
#include "LinearOnArray.h"
#include "LinearOnList.h"

#include <map>
using namespace std;

/*!
* Выполнил: Макадрай А.
* Класс ячейки для списка
*/

class maneger {
private:
	LinerOnArray<string, TPolinom> linerOnArray;
	LinerOnList<string, TPolinom> lineOnList;
	
	table<string, TPolinom>* aktiv;
public:

	bool add(string key, TPolinom value);
	bool erase(string key);
	TPolinom find(string key); 

};
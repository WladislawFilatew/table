#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "table.h"
#include "LinearOnArray.h"
#include "LinearOnList.h"
#include "OrderedOnArray.h"
#include "Tree.h"
#include "HashList.h"
#include "HashChain.h"
#include <map>
using namespace std;

/*!
* Выполнил: Макадрай А.
* Класс ячейки для списка
*/

struct Line
{
	string key;
	TPolinom value;
};

class maneger {
private:
	map<string, table<string, TPolinom>*> temp;
	table<string, TPolinom>* tec;

public:
	maneger() {
		temp.emplace("LinerOnArray", new LinerOnArray<string, TPolinom>);
		temp.emplace("LinearOnList", new LinerOnList<string, TPolinom>);
		temp.emplace("OrderedOnArray", new OrderedOnArray<string, TPolinom>);
		temp.emplace("Tree", new Tree<string, TPolinom>);
		temp.emplace("HashList", new HashList<string, TPolinom>);
		temp.emplace("HashChain", new HashChain<string, TPolinom>);
		tec = temp["LinerOnArray"];
	}
	bool Insert(string key, TPolinom value);
	bool Delete(string key);
	TPolinom* Find(string key); 
	bool ChooseTable(string name);
	friend ostream& operator<<(ostream& os, maneger& tab)
	{
		cout << (*tab.tec);
		return os;
	}
	class iterator {
		table<string,TPolinom>* tec;
	public:
		iterator(maneger men) {	
			tec = men.tec;
			tec->Reset();
		}
		Line operator*() {
			Line temp;
			temp.key = tec->GetKey();
			temp.value = tec->GetValuePtr();
			return temp;
		}
		void operator++(int n) {
			tec->GoNext();
		}
		bool end() {
			return tec->IsTabEnded();
		}
	};
	int size() { return tec->Count(); }

};

bool maneger::Insert(string key, TPolinom value) {
	auto it = temp.begin();
	bool flag = true;
	while (flag && it != temp.end()) {
		flag = (it->second->Insert(key, value) && flag);
		it++;
	}
	return flag;
}

inline bool maneger::Delete(string key)
{
	auto it = temp.begin();
	bool flag = true;
	while (flag && it != temp.end()) {
		flag = (it->second->Delete(key) && flag);
		it++;
	}
	return flag;
}

inline TPolinom* maneger::Find(string key)
{
	return tec->Find(key);
}

inline bool maneger::ChooseTable(string name)
{
	auto it = temp.begin();
	bool flag = false;
	while (!flag && it != temp.end()) {
		if (it->first == name) {
			flag = true;
			tec = it->second;
		}
		it++;
	}
	return flag;
}


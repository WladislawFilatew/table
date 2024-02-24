#pragma once
#include "TPolinom.h"


class table{
private:


public:
	virtual table* operator+() = 0;
	virtual table* operator-() = 0;
	virtual TPolinom FindPolinom(string key) = 0;
	virtual void addPolinom(TPolinom polinom) = 0;
	virtual void delPolinom(string key) = 0;
};
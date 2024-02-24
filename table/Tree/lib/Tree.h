#pragma once
#include "table.h"


class Tree: public table {
private:

public:
	virtual table* operator+() override;
	virtual table* operator-() override;
	virtual TPolinom FindPolinom(string key) override;
	virtual void addPolinom(TPolinom polinom) override;
	virtual void delPolinom(string key) override;
};
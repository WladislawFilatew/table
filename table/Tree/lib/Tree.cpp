#include "Tree.h"

table* Tree::operator+()
{
	return new Tree();
}

table* Tree::operator-()
{
	return nullptr;
}

TPolinom Tree::FindPolinom(string key)
{
	return TPolinom();
}

void Tree::addPolinom(TPolinom polinom)
{

}

void Tree::delPolinom(string key)
{

}

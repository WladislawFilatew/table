#include <gtest.h>
#include "HashChain.h"



/*!
* Выполнил: Макадрай А.
* Тесты для класса HashChain
*/

//Проверка поиска сушествующего значения
TEST(HashChain, Find_exists_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//Проверка поиска не сушествующего значения
TEST(HashChain, Find_not_exists_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//Проверка добавления в таблицу нового элемента
TEST(HashChain, insert_new_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//Проверка добавления в таблицу нового элемента с сущиствующим ключом
TEST(HashChain, insert_new_value_repit_key)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//Удаление элемента из таблицы
TEST(HashChain, delete_line)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//Удаление элемента из таблицы с несущиствуюшим ключом
TEST(HashChain, delete_line_not_key)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//Удаление элемента из пустой таблицы
TEST(HashChain, delete_line_empty_table)
{
	HashChain<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//Обход таблицы по элементно
TEST(HashChain, go_table)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	int k = 0;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		k += table.GetValuePtr();
	}
	EXPECT_EQ(k, 6);
}

//Обход получение элемента
TEST(HashChain, get_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	int k = 0;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		k += table.GetValuePtr();
	}
	EXPECT_EQ(k, 6);
}


//Обход получение ключей
TEST(HashChain, get_key)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	string s;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		s += table.GetKey();
	}
	EXPECT_EQ(s, "123");
}

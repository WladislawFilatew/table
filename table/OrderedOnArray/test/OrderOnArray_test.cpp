#include <gtest.h>
#include "OrderedOnArray.h"
#include <string>

/*!
* Выполнила: Соловьева Елизавета
* Тесты для класса OrderedOnArray
*/

//Проверка поиска сушествующего значения
TEST(OrderedOnArray, Find_exists_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//Проверка поиска не сушествующего значения
TEST(OrderedOnArray, Find_not_exists_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//Проверка добавления в таблицу нового элемента
TEST(OrderedOnArray, insert_new_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//Проверка добавления в таблицу нового элемента с сущиствующим ключом
TEST(OrderedOnArray, insert_new_value_repit_key)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//Удаление элемента из таблицы
TEST(OrderedOnArray, delete_line)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//Удаление элемента из таблицы с несущиствуюшим ключом
TEST(OrderedOnArray, delete_line_not_key)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//Удаление элемента из пустой таблицы
TEST(OrderedOnArray, delete_line_empty_table)
{
	OrderedOnArray<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//Обход таблицы по элементно
TEST(OrderedOnArray, go_table)
{
	OrderedOnArray<string, int> table;
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
TEST(OrderedOnArray, get_value)
{
	OrderedOnArray<string, int> table;
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
TEST(OrderedOnArray, get_key)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	string s;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		s += table.GetKey();
	}
	EXPECT_EQ(s, "123");
}

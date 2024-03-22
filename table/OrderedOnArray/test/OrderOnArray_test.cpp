#include <gtest.h>
#include "OrderedOnArray.h"
#include <string>

/*!
* ���������: ��������� ���������
* ����� ��� ������ OrderedOnArray
*/

//�������� ������ ������������� ��������
TEST(OrderedOnArray, Find_exists_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ������ �� ������������� ��������
TEST(OrderedOnArray, Find_not_exists_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//�������� ���������� � ������� ������ ��������
TEST(OrderedOnArray, insert_new_value)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ���������� � ������� ������ �������� � ������������ ������
TEST(OrderedOnArray, insert_new_value_repit_key)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//�������� �������� �� �������
TEST(OrderedOnArray, delete_line)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//�������� �������� �� ������� � �������������� ������
TEST(OrderedOnArray, delete_line_not_key)
{
	OrderedOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//�������� �������� �� ������ �������
TEST(OrderedOnArray, delete_line_empty_table)
{
	OrderedOnArray<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//����� ������� �� ���������
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

//����� ��������� ��������
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


//����� ��������� ������
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

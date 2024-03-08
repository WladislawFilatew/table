#include <gtest.h>
#include <string>
#include "LinearOnArray.h"

/*!
* ��������: �������� �.
* ����� ��� ������ LinearOnArray
*/

//�������� ������ ������������� ��������
TEST(LinearOnArray, Find_exists_value)
{
	LinerOnArray<string, int> table;
	table.Insert("1",1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ������ �� ������������� ��������
TEST(LinearOnArray, Find_not_exists_value)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//�������� ���������� � ������� ������ ��������
TEST(LinearOnArray, insert_new_value)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ���������� � ������� ������ �������� � ������������ ������
TEST(LinearOnArray, insert_new_value_repit_key)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//�������� �������� �� �������
TEST(LinearOnArray, delete_line)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//�������� �������� �� ������� � �������������� ������
TEST(LinearOnArray, delete_line_not_key)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//�������� �������� �� ������ �������
TEST(LinearOnArray, delete_line_empty_table)
{
	LinerOnArray<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//����� ������� �� ���������
TEST(LinearOnArray, go_table)
{
	LinerOnArray<string, int> table;
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
TEST(LinearOnArray, get_value)
{
	LinerOnArray<string, int> table;
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
TEST(LinearOnArray, get_key)
{
	LinerOnArray<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	string s;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		s += table.GetKey();
	}
	EXPECT_EQ(s, "123");
}

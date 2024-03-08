#include <gtest.h>
#include <string>
#include "LinearOnList.h"

//�������� ������ ������������� ��������
TEST(LinearOnList, Find_exists_value)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ������ �� ������������� ��������
TEST(LinerOnList, Find_not_exists_value)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//�������� ���������� � ������� ������ ��������
TEST(LinerOnList, insert_new_value)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ���������� � ������� ������ �������� � ������������ ������
TEST(LinerOnList, insert_new_value_repit_key)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//�������� �������� �� �������
TEST(LinerOnList, delete_line)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//�������� �������� �� ������� � �������������� ������
TEST(LinerOnList, delete_line_not_key)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//�������� �������� �� ������ �������
TEST(LinerOnList, delete_line_empty_table)
{
	LinerOnList<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//����� ������� �� ���������
TEST(LinerOnList, go_table)
{
	LinerOnList<string, int> table;
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
TEST(LinerOnList, get_value)
{
	LinerOnList<string, int> table;
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
TEST(LinerOnList, get_key)
{
	LinerOnList<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	string s;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		s += table.GetKey();
	}
	EXPECT_EQ(s, "123");
}

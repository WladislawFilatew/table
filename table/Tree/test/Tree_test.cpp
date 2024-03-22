#include <gtest.h>
#include "Tree.h"
#include <gtest.h>
#include <string>

/*!
* ���������: ��������� ���������
* ����� ��� ������ Tree
*/

//�������� ������ ������������� ��������
TEST(Tree, Find_exists_value)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ������ �� ������������� ��������
TEST(Tree, Find_not_exists_value)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//�������� ���������� � ������� ������ ��������
TEST(Tree, insert_new_value)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ���������� � ������� ������ �������� � ������������ ������
TEST(Tree, insert_new_value_repit_key)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//�������� �������� �� �������
TEST(Tree, delete_line)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//�������� �������� �� ������� � �������������� ������
TEST(Tree, delete_line_not_key)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//�������� �������� �� ������ �������
TEST(Tree, delete_line_empty_table)
{
	Tree<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//����� ������� �� ���������
TEST(Tree, go_table)
{
	Tree<string, int> table;
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
TEST(Tree, get_value)
{
	Tree<string, int> table;
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
TEST(Tree, get_key)
{
	Tree<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	string s;
	for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
		s += table.GetKey();
	}
	EXPECT_EQ(s, "123");
}

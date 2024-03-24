#include <gtest.h>
#include "HashChain.h"



/*!
* ��������: �������� �.
* ����� ��� ������ HashChain
*/

//�������� ������ ������������� ��������
TEST(HashChain, Find_exists_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ������ �� ������������� ��������
TEST(HashChain, Find_not_exists_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(table.Find("4"), nullptr);
}

//�������� ���������� � ������� ������ ��������
TEST(HashChain, insert_new_value)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	EXPECT_EQ(*table.Find("2"), 2);
}

//�������� ���������� � ������� ������ �������� � ������������ ������
TEST(HashChain, insert_new_value_repit_key)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Insert("3", 12);
	EXPECT_EQ(temp, false);
}

//�������� �������� �� �������
TEST(HashChain, delete_line)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	table.Delete("2");
	EXPECT_EQ(table.Find("2"), nullptr);
}

//�������� �������� �� ������� � �������������� ������
TEST(HashChain, delete_line_not_key)
{
	HashChain<string, int> table;
	table.Insert("1", 1);
	table.Insert("2", 2);
	table.Insert("3", 3);
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//�������� �������� �� ������ �������
TEST(HashChain, delete_line_empty_table)
{
	HashChain<string, int> table;
	bool temp = table.Delete("4");
	EXPECT_EQ(temp, false);
}

//����� ������� �� ���������
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

//����� ��������� ��������
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


//����� ��������� ������
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

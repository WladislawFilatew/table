#include <gtest.h>
#include "..\lib\stack_lib.h"


TEST(Stack, you_can_create_an_object)
{
	ASSERT_NO_THROW(MyStack<int> a);
}

TEST(Stack, can_check_for_emptiness)
{
	MyStack<int> temp;
	EXPECT_EQ(true,temp.empty());
}

TEST(Stack, the_stac_is_not_empty)
{
	MyStack<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	EXPECT_EQ(false, temp.empty());
}

TEST(Stack, can_add_objects_1_object)
{
	MyStack<int> temp;
	temp.push(1);
	EXPECT_EQ(1, temp.size());
}

TEST(Stack, can_add_objects_multiple_objects)
{
	MyStack<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	EXPECT_EQ(10, temp.size());
}

TEST(Stack, error_clearing_an_empty_stack)
{
	MyStack<int> a;
	ASSERT_ANY_THROW(a.pop());
}

TEST(Stack, there_is_no_error_when_deleting_an_element_from_an_object)
{
	MyStack<int> a;
	a.push(1);
	ASSERT_NO_THROW(a.pop());
}

TEST(Stack, can_clear_the_stack)
{
	MyStack<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i);
	}
	for (int i = 0; i < 10; i++) {
		temp.pop();
	}
	EXPECT_EQ(0, temp.size());
}

TEST(Stack, can_get_an_element_from_the_stack)
{
	MyStack<int> temp;
	for (int i = 0; i < 10; i++) {
		temp.push(i + 1);
	}
	for (int i = 0; i < 4; i++) {
		temp.pop();
	}
	EXPECT_EQ(5, temp.top());
}

TEST(Stack, error_when_getting_an_element_from_an_empty_stack)
{
	MyStack<int> a;
	ASSERT_ANY_THROW(a.top());
}

TEST(Stack, can_get_an_object_without_an_error)
{
	MyStack<int> a;
	a.push(1);
	ASSERT_NO_THROW(a.top());
}

TEST(Stack, can_bypass_the_object)
{
	MyStack<int> temp;
	for (int i = 0; i < 4; i++) {
		temp.push(i + 1);
	}
	int sum = 0;
	while (!temp.empty()) {
		sum += temp.top();
		temp.pop();
	}
	EXPECT_EQ(10, sum);
}
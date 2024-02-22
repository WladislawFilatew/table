#include "TPolinom.h"
#include <gtest.h>

TEST(Polinom, Created_polinom_is_empty) {
	TPolinom a;
	EXPECT_EQ(a.ToString(), "");
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	TPolinom a("x");
	EXPECT_NE("", a.ToString());

}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	TPolinom a("xy + 4xy");
	EXPECT_EQ('5', a.ToString()[0]);
}

TEST(Polinom, Coefficients_dont_add_up_if_degrees_are_different) {
	TPolinom a("xy + 4x^2y^2");
	EXPECT_EQ("4x^2y^2 + xy", a.ToString());
}

TEST(Polinom, Monom_delete_if_coefficient_equal_zero) {
	TPolinom a("0xy + 4x^2y^2");
	EXPECT_EQ("4x^2y^2", a.ToString());
}

TEST(Polinom, Can_not_get_monom_from_empty_polinom) {
	TPolinom a("xy + 4x^2y^2");
	bool flag = TMonom("4x^2y^2") == a.list[0];
	EXPECT_EQ(flag, true);
}

TEST(Polinom, Copied_polinom_is_equal_copiable) {
	TPolinom a("xy + 4x^2y^2");
	TPolinom b;
	b = a;
	bool flag = a == a;
	EXPECT_EQ(flag, true);
}

TEST(Polinom, Assigned_polinom_is_equal_assignable) {
	TPolinom a("xy + 4x^2y^2");
	TPolinom b;
	b = a;
	bool flag = a == b;
	EXPECT_EQ(flag, true);
}

TEST(Polinom, Correct_adding_operator) {
	TPolinom a("xy + 4x^2y^2");
	a + TMonom("xy");
	EXPECT_EQ(a.ToString(),"4x^2y^2 + 2xy");
}

TEST(Polinom, Correct_constant_multiply) {
	TPolinom a("xy + 4x^2y^2");
	a = a * 3;
	EXPECT_EQ(a.ToString(), "12x^2y^2 + 3xy");
}

TEST(Polinom, Correct_monom_multiply) {
	TPolinom a("xy + 4x^2y^2");
	a = a * TMonom("2x");
	EXPECT_EQ(a.ToString(), "8x^3y^2 + 2x^2y");
}

TEST(Polinom, Correct_polinom_enter) {
	TPolinom a("x + xyz");
	EXPECT_EQ("xyz + x", a.ToString());
}

TEST(Polinom, Correct_multiply_polinom1) {
	TPolinom a("xy + 4x^2y^2");
	a = a * TPolinom("2x");
	EXPECT_EQ(a.ToString(), "8x^3y^2 + 2x^2y");
}

TEST(Polinom, Correct_multiply_polinom2) {
	TPolinom a("xy + 4x^2y^2");
	a = a * TPolinom("2x + y");
	EXPECT_EQ(a.ToString(), "8x^3y^2 + 4x^2y^3 + 2x^2y + xy^2");
}

TEST(Polinom, Correct_multiply_polinom3) {
	TPolinom a;
	a = a * TPolinom("2x + y");
	EXPECT_EQ(a.ToString(), "");
}

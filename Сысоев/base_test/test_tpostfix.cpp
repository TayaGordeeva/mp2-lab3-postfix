#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_postfix_with_str)
{
	 string p = "1+2-3";
	 TPostfix p1;
	 p1.Infix(p);
	 p1.GetPostfix();
	 ASSERT_NO_THROW(p1.ToPostfix());
}

TEST(TPostfix, infix_form_correct)
{
	string p = "1+2-3/2*6";
	TPostfix p1;
	p1.Infix(p);
	EXPECT_EQ(p1.GetInfix(), "1+2-3/2*6");
}

TEST(TPostfix, postfix_form_correct)
{
	string p = "1*2-3";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.GetPostfix(), "12*3-");
}

TEST(TPostfix, expression_with_wrong_lexem)
{
	string p = "1!2-3";
	TPostfix p1;
	ASSERT_NO_THROW(p1.ToPostfix());
}

TEST(TPostfix, expression_with_wrong_open_brackets)
{
	string p = "1*(2-3";
	TPostfix p1;
	ASSERT_NO_THROW(p1.ToPostfix());
}

TEST(TPostfix, expression_with_wrong_close_brackets)
{
	string p = "1*2-3)";
	TPostfix p1;
	ASSERT_NO_THROW(p1.ToPostfix());
}

TEST(TPostfix, calculate_with_addition)
{
	string p = "1+2";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), 3);
}

TEST(TPostfix, calculate_with_sub)
{
	string p = "1-2";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), -1);
}

TEST(TPostfix, calculate_with_multy)
{
	string p = "1*2";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), 2);
}

TEST(TPostfix, calculate_with_div)
{
	string p = "4/2";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), 2);
}

TEST(TPostfix, calculate_with_incorrect_div)
{
	string p = "4:2";
	TPostfix p1;
	ASSERT_NO_THROW(p1.ToPostfix());

}

TEST(TPostfix, calculate_with_simple_expression_correct)
{
	string p = "1*2-3";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), -1);
}

TEST(TPostfix, calculate_with_simple_expression_with_brackets_correct)
{
	string p = "2*(2-3)";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), -2);
}

TEST(TPostfix, calculate_with_expression_correct)
{
	string p = "1+2*(7-4*2)+4/2";
	TPostfix p1;
	p1.Infix(p);
	p1.ToPostfix();
	EXPECT_EQ(p1.Calculate(), 1);
}
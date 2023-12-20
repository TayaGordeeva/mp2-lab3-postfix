#include <stack.h>
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));

}

TEST(TStack, can_push_elem)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m.Push(1));
}

TEST(TStack, can_top_elem)
{
	TStack<int> m(5);
	m.Push(1);
	EXPECT_EQ(m.Top(), 1);
}

TEST(TStack, cant_top_empty_stack)
{
	TStack<int> m(1);
	ASSERT_ANY_THROW(m.Top());
}

TEST(TStack, can_pop_elem)
{
	TStack<int> m(5);
	m.Push(1);
	ASSERT_NO_THROW(m.Pop());
}

TEST(TStack, cant_pop_empty_stack)
{
	TStack<int> m(1);
	ASSERT_ANY_THROW(m.Pop());
}

TEST(TStack, can_copy_stack)
{
	TStack<int> m1(5);
	ASSERT_NO_THROW(TStack<int> m2(m1));
}

TEST(TStack, stack_is_empty)
{
	TStack<int> m(5);
	EXPECT_EQ(1, m.IsEmpty());
}

TEST(TStack, stack_is_full)
{
	TStack<int> m(5);
	m.Push(1); m.Push(1); m.Push(1); m.Push(1); m.Push(1);
	EXPECT_EQ(1, m.IsFull());
}
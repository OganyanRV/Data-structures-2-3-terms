/* #include "postfix.h"
#include <gtest.h>


TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW (Stack<int> A(5));
}

TEST(Stack, throws_when_create_Stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> A(-2));
}

TEST(Stack, throws_when_create_Stack_with_very_big_length)
{
	ASSERT_ANY_THROW(Stack<int> A(51));
}

TEST(Stack, can_get_length)
{
	Stack<int> A(3);
	EXPECT_EQ(3, A.getSize());
}

TEST(Stack, can_get_top)
{
	Stack<int> A(2);
	EXPECT_EQ(-1, A.getTop());
}

TEST(Stack, can_get_top_2)
{
	Stack<double> A(2);
	A.push(1.5);
	A.pop();
	EXPECT_EQ(-1, A.getTop());
}

TEST(Stack,can_push)
{
	Stack<int> A(5);
	ASSERT_NO_THROW(A.push(1));
}

TEST(Stack,can_pop)
{
	Stack<char> A(5);
	A.push('a');
	ASSERT_NO_THROW(A.pop());
}

TEST(Stack,can_push_and_pop_right)
{
	Stack<int> A(5);
	A.push(5);
	EXPECT_EQ(5, A.pop());
}

TEST(Stack,can_look_right)
{
	Stack<char> A(5);
	A.push('s');
	EXPECT_EQ('s', A.look());
}

TEST(Stack, throws_when_full)
{
	Stack<bool> A(2);
	A.push(true);
	A.push(false);
	ASSERT_ANY_THROW(A.push(true));
}
TEST(Stack, throws_when_free)
{
	Stack<int> A(2);
	ASSERT_ANY_THROW(A.pop());
}

TEST(Stack, compare_stack_full_return_true)
{
	Stack<float> S(2);
	S.push(1.5);
	S.push(0.5);
	EXPECT_EQ(true,S.getTop()>=S.getTop());
}

TEST(Stack, compare_stack_empty_return_true)
{
	Stack<int> S(2);
	EXPECT_EQ(true,S.getTop()<0);
}

//--------------------------------------------------------------

TEST(Postfix, test_name1)
{
	string s = "1";
	Postfix P(s);
	ASSERT_NO_THROW(P.ConvertToPolish());
	double rez = P.Result();
	EXPECT_EQ(rez,1);
}

TEST(Postfix, test_name2)
{
	string s = "3+4*2/(1-5)^2=";
	Postfix P(s);
	ASSERT_NO_THROW(P.ConvertToPolish());
}

TEST(Postfix, test_name3)
{
	string s = "3+4*2/(1-5)^2";
    Postfix P(s);
	ASSERT_NO_THROW(P.ConvertToPolish());
}

TEST(Postfix, test_name4)
{
	string s1 = "3+4*2/(1-5)^2";
	string s2 = "3 4 2 * 1 5 - 2 ^ / + ";
	Postfix P(s1);
	EXPECT_EQ(s2,P.ConvertToPolish());
}

TEST(Postfix, test_name5)
{
	string s1 = "3+4*2/(1-5)^2=";
	string s2 = "3 4 2 * 1 5 - 2 ^ / + ";
    Postfix P(s1);
	EXPECT_EQ(s2,P.ConvertToPolish());
}

TEST(Postfix, test_name6)
{
	string s = "3+4*2/(1-5)^2=";
	Postfix P(s);
	double rez = P.Result();
	EXPECT_EQ(rez,3.5);
}

TEST(Postfix, test_name7)
{
	string s = "(((999-99+100)*10)^(1/2))/10";
    Postfix P(s);
	double rez = P.Result();
	EXPECT_EQ(rez,10);
}

TEST(Postfix, test_name8)
{
	string s = "(7-";
	ASSERT_ANY_THROW(Postfix P(s));
}

TEST(Postfix, test_name9)
{
	string s = "--6";
    ASSERT_ANY_THROW(Postfix P(s));
}

TEST(Postfix, test_name10)
{
	string s = "34++23";
	ASSERT_ANY_THROW(Postfix P(s));
}

TEST(Postfix, test_name11)
{
	string s = "!$&";
	ASSERT_ANY_THROW(Postfix P(s));
}

TEST(Postfix, test_name12)
{
	string s = "- ";
	ASSERT_ANY_THROW(Postfix P(s));
}

TEST(Postfix, test_name13)
{
	string s = "5/0";
    Postfix P(s);
	ASSERT_NO_THROW(P.ConvertToPolish());
	EXPECT_EQ("5 0 / ",P.ConvertToPolish());
	ASSERT_ANY_THROW(P.Result());
}

TEST(Postfix, test_name14)
{
	string s = "-40-(-50)";
    Postfix P(s);
	ASSERT_NO_THROW(P.ConvertToPolish());
}

TEST(Postfix, test_name15)
{
	string s = "-40-(-50)";
    Postfix P(s);
	ASSERT_NO_THROW(P.Result());
}

TEST(Postfix, test_name16)
{
	string s = "-40-(-50)";
    Postfix P(s);
	EXPECT_EQ(10, P.Result());
}

TEST(Postfix, test_name17)
{
	string s1 = "3.2+4.1*2.5/(1.66-5.05)^2=";
	string s2 = "3.2 4.1 2.5 * 1.66 5.05 - 2 ^ / + ";
    Postfix P(s1);
	EXPECT_EQ(s2,P.ConvertToPolish());
}

TEST(Postfix, test_name18)
{
	string s = "9^1.5";
    Postfix P(s);
	EXPECT_EQ(27, P.Result());
}

TEST(Postfix, test_name19)
{
	string s = "-100.95-(-99.95)";
    Postfix P(s);
	EXPECT_EQ(-1, P.Result());
}
 */
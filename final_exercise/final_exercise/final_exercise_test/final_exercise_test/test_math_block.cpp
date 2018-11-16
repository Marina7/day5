#include "pch.h"
#include "CppUnitTest.h"

#include "..\..\math_block.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace final_exercise_test
{		
	TEST_CLASS(MathBlockTest)
	{
	public:
		
		TEST_METHOD(math_block_identity_returns_input)
		{
			identity id;
			Assert::AreEqual(1.0, id.evaluate(1));
		}

		TEST_METHOD(math_block_identity_negative)
		{
			identity id;
			Assert::AreEqual(-5.0, id.evaluate(-5));
		}

		TEST_METHOD(math_block_addition_default)
		{
			addition add;
			Assert::AreEqual(-5.0, add.evaluate(-5));
		}

		TEST_METHOD(math_block_addition_positive)
		{
			addition add(9);
			Assert::AreEqual(4.0, add.evaluate(-5));
		}

		TEST_METHOD(math_block_addition_negative)
		{
			addition add(-5);
			Assert::AreEqual(0.0, add.evaluate(5));
		}

		TEST_METHOD(math_block_multiplication_zero)
		{
			multiplication m(0);
			Assert::AreEqual(0.0, m.evaluate(5));
		}

		TEST_METHOD(math_block_multiplication_neg)
		{
			multiplication m(-2);
			Assert::AreEqual(-10.0, m.evaluate(5));
		}

		TEST_METHOD(math_block_multiplication_pos)
		{
			multiplication m(3);
			Assert::AreEqual(15.0, m.evaluate(5));
		}

		TEST_METHOD(math_block_multiplication_inf)
		{
			multiplication m(std::numeric_limits<double>::infinity());
			Assert::AreEqual(std::numeric_limits<double>::infinity(), m.evaluate(5));
		}

		TEST_METHOD(math_block_power_zero)
		{
			power p(0);
			Assert::AreEqual(1.0, p.evaluate(5));
		}

		TEST_METHOD(math_block_power_inf)
		{
			power p(std::numeric_limits<double>::infinity());
			Assert::AreEqual(std::numeric_limits<double>::infinity(), p.evaluate(5));
		}

		TEST_METHOD(math_block_power_neg_inf)
		{
			power p(-std::numeric_limits<double>::infinity());
			Assert::AreEqual(0.0, p.evaluate(5));
		}

		TEST_METHOD(math_block_power_inf_power_inf)
		{
			power p(std::numeric_limits<double>::infinity());
			Assert::AreEqual(std::numeric_limits<double>::infinity(), p.evaluate(std::numeric_limits<double>::infinity()));
		}

		TEST_METHOD(math_block_limit_under_min)
		{
			limit l(0, 1);
			Assert::AreEqual(0.0, l.evaluate(-1));
		}

		TEST_METHOD(math_block_limit_above_max)
		{
			limit l(0, 1);
			Assert::AreEqual(1.0, l.evaluate(2));
		}

		TEST_METHOD(math_block_limit_in_interval)
		{
			limit l(0, 1);
			Assert::AreEqual(0.5, l.evaluate(0.5));
		}

		TEST_METHOD(math_block_limit_switched_limits)
		{
			auto func = []() { limit l(9, 5); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(math_block_condition_less)
		{
			condition c(5);
			Assert::AreEqual(-1.0, c.evaluate(4));
		}

		TEST_METHOD(math_block_condition_greater)
		{
			condition c(5);
			Assert::AreEqual(1.0, c.evaluate(7));
		}

		TEST_METHOD(math_block_condition_equal)
		{
			condition c(5);
			Assert::AreEqual(0.0, c.evaluate(5));
		}



	};
}
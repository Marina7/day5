#include "pch.h"
#include "CppUnitTest.h"

#include "..\..\linear_sequence.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace final_exercise_test
{
	TEST_CLASS(LinearSequenceTest)
	{
	public:

		TEST_METHOD(linear_sequence_create_default)
		{
			linear_sequence lin_seq;
			Assert::AreEqual(L"", lin_seq.show_sequence());
			Assert::AreEqual(0, lin_seq.number_of_blocks());
		}

		TEST_METHOD(linear_sequence_add_math_blocks)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(identity());
			lin_seq.add_math_block(addition(2));
			lin_seq.add_math_block(multiplication(2));
			lin_seq.add_math_block(power(2));
			lin_seq.add_math_block(limit(0,1));
			lin_seq.add_math_block(condition(2));

			Assert::AreEqual(6, lin_seq.number_of_blocks());
		}

		TEST_METHOD(linear_sequence_evaluate_sequence)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(identity());
			lin_seq.add_math_block(addition(2));

			Assert::AreEqual(2, lin_seq.number_of_blocks());

			Assert::AreEqual(5, lin_seq.evaluate(3));
		}
		
	};
}
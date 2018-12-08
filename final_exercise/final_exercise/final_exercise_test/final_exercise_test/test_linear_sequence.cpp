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
			Assert::AreEqual(std::wstring(L"x"), lin_seq.show_sequence());
			Assert::AreEqual(0u, lin_seq.number_of_blocks());
		}

		TEST_METHOD(linear_sequence_add_math_blocks)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<identity>());
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));
			lin_seq.add_math_block(std::make_unique<limit>(0,1));
			lin_seq.add_math_block(std::make_unique<condition>(2));

			Assert::AreEqual(6u, lin_seq.number_of_blocks());
		}

		TEST_METHOD(linear_sequence_evaluate_sequence)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<identity>());
			lin_seq.add_math_block(std::make_unique<addition>(2));

			Assert::AreEqual(2u, lin_seq.number_of_blocks());

			Assert::AreEqual(5.0, lin_seq.evaluate(3));
		}

		TEST_METHOD(linear_sequence_priorities_ignored)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));

			Assert::AreEqual(2u, lin_seq.number_of_blocks());

			Assert::AreEqual(10.0, lin_seq.evaluate(3));
		}

		TEST_METHOD(linear_sequence_delete_first_block)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.delete_math_block(0); // 0-index, user on console will write 1

			Assert::AreEqual(2u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x * 2)^2"), lin_seq.show_sequence());
		}

		TEST_METHOD(linear_sequence_delete_last_block)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.delete_math_block(2);

			Assert::AreEqual(2u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"x + 2 * 2"), lin_seq.show_sequence());
		}
		
		TEST_METHOD(linear_sequence_delete_middle_block)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.delete_math_block(1);

			Assert::AreEqual(2u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x + 2)^2"), lin_seq.show_sequence());
		}

		TEST_METHOD(linear_sequence_delete_after_sequence_end_block)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.delete_math_block(3);

			Assert::AreEqual(3u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x + 2 * 2)^2"), lin_seq.show_sequence());
		}

		TEST_METHOD(linear_sequence_delete_before_first_block)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.delete_math_block(-1);

			Assert::AreEqual(3u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x + 2 * 2)^2"), lin_seq.show_sequence());
		}

		TEST_METHOD(linear_sequence_move_to_first_position)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.move_to_first_position(2);

			Assert::AreEqual(3u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x)^2 + 2 * 2"), lin_seq.show_sequence());
		}

		TEST_METHOD(linear_sequence_move_to_first_position_wrong_index)
		{
			linear_sequence lin_seq;
			lin_seq.add_math_block(std::make_unique<addition>(2));
			lin_seq.add_math_block(std::make_unique<multiplication>(2));
			lin_seq.add_math_block(std::make_unique<power>(2));

			Assert::AreEqual(3u, lin_seq.number_of_blocks());

			lin_seq.move_to_first_position(3);

			Assert::AreEqual(3u, lin_seq.number_of_blocks());
			Assert::AreEqual(std::wstring(L"(x + 2 * 2)^2"), lin_seq.show_sequence());
		}

	};
}
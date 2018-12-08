#include "pch.h"
#include "linear_sequence.h"
#include <sstream>

linear_sequence::linear_sequence()
{
}

size_t linear_sequence::number_of_blocks() const
{
	return sequence.size();
}

void linear_sequence::add_math_block(std::unique_ptr<math_block> block)
{
	sequence.emplace_back(std::move(block));
}

void linear_sequence::delete_math_block(size_t index)
{
	if (index < 0 || index >= sequence.size())
		return; // nothing happens
	sequence.erase(sequence.begin() + index);
}

void linear_sequence::move_to_first_position(size_t index)
{
	if (index < 1 || index >= sequence.size())
		return; // do nothing
	auto block = std::move(sequence[index]);
	sequence.erase(sequence.begin() + index);
	sequence.insert(sequence.begin(), std::move(block));
}

double linear_sequence::evaluate(double input) const
{
	for (const auto& block : sequence)
	{
		input = (*block).evaluate(input);
	}
	return input;
}

std::wstring linear_sequence::show_sequence() const
{
	std::wstring input(L"x");
	for (const auto& block : sequence)
	{
		input = (*block).print(input);
	}
	return input;
}

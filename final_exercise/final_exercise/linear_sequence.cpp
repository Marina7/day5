#include "pch.h"
#include "linear_sequence.h"

linear_sequence::linear_sequence()
{
}

size_t linear_sequence::number_of_blocks() const
{
	return sequence.size();
}

void linear_sequence::add_math_block(const math_block & math_block)
{
}

void linear_sequence::delete_math_block(size_t index)
{
	if (index < 0 || index >= sequence.size())
		return; // TODO: maybe throw
	// TODO: delete math_block from sequence
}

void linear_sequence::move_to_first_position(size_t index)
{
}

double linear_sequence::evaluate(double input) const
{
	return 0.0;
}

std::wstring linear_sequence::show_sequence() const
{
	return std::wstring();
}

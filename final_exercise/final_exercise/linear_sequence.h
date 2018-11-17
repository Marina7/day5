#pragma once
#include <vector>
#include "math_block.h"

class linear_sequence
{
public:
	linear_sequence();
	~linear_sequence() = default;
	
	int number_of_blocks();
	void add_math_block(const math_block& math_block);
	void delete_math_block(size_t index);
	void move_to_first_position(size_t index);

	double evaluate(double input);

	std::wstring show_sequence();

};

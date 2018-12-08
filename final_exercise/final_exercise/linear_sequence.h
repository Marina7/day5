#pragma once
#include <vector>
#include "math_block.h"
#include <memory>


class linear_sequence
{
	std::vector<std::unique_ptr<math_block>> sequence;
public:
	linear_sequence();
	~linear_sequence() = default;
	
	size_t number_of_blocks() const;
	void add_math_block(std::unique_ptr<math_block> block);
	void delete_math_block(size_t index);
	void move_to_first_position(size_t index);

	double evaluate(double input) const;

	std::wstring show_sequence() const;

};

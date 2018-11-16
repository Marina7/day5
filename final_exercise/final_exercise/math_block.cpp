#include "pch.h"
#include "math_block.h"
#include <algorithm> // std::pow, std::clamp

double identity::evaluate(double input) const
{
	return input;
}

addition::addition(double addend) : addend{ addend }
{ }

double addition::evaluate(double input) const
{
	return input + addend;
}

multiplication::multiplication(double factor) : factor{ factor }
{ }

double multiplication::evaluate(double input) const
{
	return input * factor;
}

power::power(double exponent) : exponent{ exponent }
{ }

double power::evaluate(double input) const
{
	return std::pow(input, exponent);
}

limit::limit(double min_value, double max_value) : min_value{ min_value }, max_value{ max_value }
{ }

double limit::evaluate(double input) const
{
	return std::clamp(input, min_value, max_value);
}

condition::condition(double compare_to) : compare_to{ compare_to }
{ }

double condition::evaluate(double input) const
{
	if (input < compare_to) return -1;
	if (input > compare_to) return 1;
	return 0;
}

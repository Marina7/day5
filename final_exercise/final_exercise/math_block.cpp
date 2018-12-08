#include "pch.h"
#include "math_block.h"
#include <algorithm> // std::pow, std::clamp
#include <stdexcept>
#include <sstream>

double identity::evaluate(double input) const
{
	return input;
}

std::wstring identity::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << L"id(" << input << L")";
	return ws.str();
}

addition::addition(double addend) : addend{ addend }
{ }

double addition::evaluate(double input) const
{
	return input + addend;
}

std::wstring addition::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << input << L" + " << addend;
	return ws.str();
}

multiplication::multiplication(double factor) : factor{ factor }
{ }

double multiplication::evaluate(double input) const
{
	return input * factor;
}

std::wstring multiplication::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << input << L" * " << factor;
	return ws.str();
}

power::power(double exponent) : exponent{ exponent }
{ }

double power::evaluate(double input) const
{
	return std::pow(input, exponent);
}

std::wstring power::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << L"(" << input << L")^" << exponent;
	return ws.str();
}

limit::limit(double min_value, double max_value) : min_value{ min_value }, max_value{ max_value }
{
	if (max_value < min_value)
		throw std::invalid_argument("Wrong limit interval.");
}

double limit::evaluate(double input) const
{
	return std::clamp(input, min_value, max_value);
}

std::wstring limit::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << L"limit(" << input << L", " << min_value << L", " << max_value << L")";
	return ws.str();
}

condition::condition(double compare_to) : compare_to{ compare_to }
{ }

double condition::evaluate(double input) const
{
	if (input < compare_to) return -1;
	if (input > compare_to) return 1;
	return 0;
}

std::wstring condition::print(const std::wstring& input) const
{
	std::wstringstream ws;
	ws << L"compare(" << input << L", " << compare_to << L")";
	return ws.str();
}

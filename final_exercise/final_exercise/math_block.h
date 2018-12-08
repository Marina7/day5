#pragma once
#include <string>

class math_block
{
public:
	virtual double evaluate(double input) const = 0;
	virtual std::wstring print(const std::wstring& input) const = 0;
	virtual ~math_block() = default;
};

class identity : public math_block
{
public:
	identity() = default;
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};

class addition : public math_block
{
	double addend;
public:
	addition(double addend = 0);
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};

class multiplication : public math_block
{
	double factor;
public:
	multiplication(double factor = 1);
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};

class power : public math_block
{
	double exponent;
public:
	power(double exponent = 1);
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};

class limit : public math_block
{
	double min_value, max_value;
public:
	limit(double min_value, double max_value);
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};

class condition : public math_block
{
	double compare_to;
public:
	condition(double compare_to);
	double evaluate(double input) const override;
	std::wstring print(const std::wstring& input) const override;
};
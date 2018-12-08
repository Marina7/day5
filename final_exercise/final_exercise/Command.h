#pragma once

class Command
{
	std::wstring name;

public:
	virtual void executeCommand() const = 0;
	virtual std::wstring help() const = 0;

};


class AboutAppCommand : public Command
{
public:
	void executeCommand() const;
	std::wstring help() const;
};

class CreateSequenceCommand : public Command
{

};

class AddMathBlockCommand : public Command
{

};

class DeleteMathBlockCommand : public Command
{
};

class MoveMathBlockToFrontCommand : public Command
{

};

class ShowSequenceCommand : public Command
{

};

class EvaluateInputCommand : public Command
{

};

class EvaluateMultipleFromFileCommand : public Command
{

};
#include "pch.h"
#include "CommandFactory.h"

std::unique_ptr<Command> CommandFactory::createCommand(const std::wstring& command_name)
{
	if (command_name == L"about")
		return std::make_unique<AboutAppCommand>();
	return std::make_unique<AboutAppCommand>();
}

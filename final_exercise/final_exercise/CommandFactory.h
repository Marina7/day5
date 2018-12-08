#pragma once

#include "Command.h"

struct CommandFactory
{

	std::unique_ptr<Command> createCommand(const std::wstring& command_name);

};
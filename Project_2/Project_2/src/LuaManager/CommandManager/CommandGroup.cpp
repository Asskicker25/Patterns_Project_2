#include "CommandGroup.h"

void CommandGroup::SetCommandGroupType(const std::string& type)
{
	if (type == "Sequence")
	{
		this->groupType = SEQUENCE;
	}
	else if (type == "Parallel")
	{
		this->groupType = PARALLEL;
	}
	else
	{
		this->groupType = SEQUENCE;
	}
}

void CommandGroup::Start()
{
	if (groupType == SEQUENCE)
	{
		for (BaseCommand* command : listOfCommands)
		{
			if (command->IsCommandCompleted()) continue;

			command->StartCommand();

			return;
		}
	}
	else if (groupType == PARALLEL)
	{
		for (BaseCommand* command : listOfCommands)
		{
			command->StartCommand();
		}
	}
}

void CommandGroup::Update()
{
	if (groupType == SEQUENCE)
	{
		for (BaseCommand* command : listOfCommands)
		{
			if (command->IsCommandCompleted()) continue;

			if (!command->inProgress)
			{
				command->StartCommand();
			}

			command->Update();

			return;
		}
	}
	else if (groupType == PARALLEL)
	{
		for (BaseCommand* command : listOfCommands)
		{
			command->Update();
		}
	}
}

void CommandGroup::AddCommand(BaseCommand* command)
{
	listOfCommands.push_back(command);
}

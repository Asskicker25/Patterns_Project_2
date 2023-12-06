#include <Graphics/Debugger.h>

#include "CommandManager.h"

int CommandManager::currentGroupIndex = 0;
CommandGroup* CommandManager::currentCommandGroup = nullptr;

std::vector<CommandGroup*> CommandManager::listOfCommandGroups;


void CommandManager::BeginCommandGroup(
	const std::string& friendlyName, const std::string& groupType, int repeatCount)
{
	CommandGroup* newCommandGroup = new CommandGroup();

	newCommandGroup->id = currentGroupIndex;
	newCommandGroup->friendlyName = friendlyName;
	newCommandGroup->repeatCount = repeatCount;
	newCommandGroup->SetCommandGroupType(groupType);


	Debugger::Print("Begin Command Group : ", friendlyName);

	currentCommandGroup = newCommandGroup;
	currentGroupIndex++;
}

void CommandManager::EndCommandGroup()
{
	currentCommandGroup->Start();
	currentCommandGroup = nullptr;
}

void CommandManager::AddCommand(BaseCommand* command)
{
	if (currentCommandGroup == nullptr)
	{
		std::cout << "No Command Group Available!!!" << std::endl;
		return;
	}

	currentCommandGroup->AddCommand(command);
}


void CommandManager::Update(float deltaTime)
{
	for (CommandGroup* commandGroup : listOfCommandGroups)
	{
		commandGroup->Update();
	}

	
}

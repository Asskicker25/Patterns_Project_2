#include <Graphics/Debugger.h>

#include "CommandManager.h"

CommandManager& CommandManager::GetInstance()
{
	static CommandManager instance;
	return instance;
}

void CommandManager::BeginCommandGroup(
	const std::string& friendlyName, const std::string& groupType, int repeatCount)
{
	CommandGroup* newCommandGroup = new CommandGroup();

	newCommandGroup->id = currentGroupIndex;
	newCommandGroup->friendlyName = friendlyName;
	newCommandGroup->repeatCount = repeatCount;
	newCommandGroup->SetCommandGroupType(groupType);

	listOfCommandGroups.push_back(newCommandGroup);

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
	currentCommand = command;

	command->commandGroup = currentCommandGroup;
}

void CommandManager::BindGameObject(GameObject* gameObject)
{
	currentGameObject = gameObject;
}

GameObject* CommandManager::GetBoundGameObject()
{
	if (currentGameObject == nullptr)
	{
		Debugger::Print("No Game Object Bound!!");
	}

	return currentGameObject;
}

void CommandManager::Update(float deltaTime)
{
	for (CommandGroup* commandGroup : listOfCommandGroups)
	{
		commandGroup->Update();
	}

	
}

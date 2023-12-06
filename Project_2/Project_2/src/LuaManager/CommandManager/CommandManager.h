#pragma once

#include "CommandGroup.h"

class CommandManager
{
public:

	//Commands
	static void BeginCommandGroup(
		const std::string& friendlyName, const std::string& groupType, int repeatCount = 0);
	static void EndCommandGroup();
	static void AddCommand(BaseCommand* command);

	static void Update(float deltaTime);

	static int currentGroupIndex;
	static CommandGroup* currentCommandGroup;

	static std::vector<CommandGroup*> listOfCommandGroups;

};


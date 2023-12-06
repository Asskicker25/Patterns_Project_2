#pragma once

#include "CommandGroup.h"
#include <unordered_map>

class CommandManager
{
public:

	//Commands
	static CommandManager& GetInstance();

	void BeginCommandGroup(
		const std::string& friendlyName, const std::string& groupType, int repeatCount = 0);
	void EndCommandGroup();
	void AddCommand(BaseCommand* command);

	void Update(float deltaTime);

	int currentGroupIndex = 0;
	CommandGroup* currentCommandGroup = nullptr;

	std::vector<CommandGroup*> listOfCommandGroups;


};


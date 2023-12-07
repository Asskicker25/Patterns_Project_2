#pragma once

#include <vector>
#include <string>
#include "BaseCommand.h"

enum CommandGroupType
{
	SEQUENCE,
	PARALLEL,
};

struct CommandGroup
{

public:

	int id;
	std::string friendlyName;
	int repeatCount = 0;
	CommandGroupType groupType;
	std::vector<BaseCommand*> listOfCommands;

	void SetCommandGroupType(const std::string& type);

	void Start();
	void Update();

	void AddCommand(BaseCommand* command);
	BaseCommand* GetLastCommand();

};


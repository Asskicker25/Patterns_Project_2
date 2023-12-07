#pragma once

#include "../../GameObject/GameObject.h"
#include <Graphics/Time.h>

class BaseCommand
{
public:
	bool inProgress = false;

	virtual ~BaseCommand() {};

	virtual void StartCommand() = 0;
	virtual void Update() = 0;
	virtual void EndCommand() = 0;
	virtual bool IsCommandCompleted() = 0;
};


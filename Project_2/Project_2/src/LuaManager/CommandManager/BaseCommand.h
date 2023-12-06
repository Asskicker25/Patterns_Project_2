#pragma once

#include "../../GameObject/GameObject.h"

class BaseCommand
{
public:
	virtual ~BaseCommand() {};

	virtual void StartCommand() = 0;
	virtual void Update() = 0;
	virtual void EndCommand() = 0;
	virtual bool IsCommandCompleted() = 0;
};


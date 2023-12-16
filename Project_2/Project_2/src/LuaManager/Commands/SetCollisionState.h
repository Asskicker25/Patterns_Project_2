#pragma once

#include "../CommandManager/BaseCommand.h"

class SetCollisionState : public BaseCommand
{

public:
	SetCollisionState(PhysicsObject* phyObj, bool state);

private:
	// Inherited via BaseCommand
	void StartCommand() override;
	void Update() override;
	void EndCommand() override;
	bool IsCommandCompleted() override;

	bool state = false;
	bool isStateUpdated = false;
	PhysicsObject* phyObj = nullptr;

};


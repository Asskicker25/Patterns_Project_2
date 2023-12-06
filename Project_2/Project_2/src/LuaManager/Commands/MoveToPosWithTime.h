#pragma once

#include "../CommandManager/BaseCommand.h"

class MoveToPosWithTime : public BaseCommand
{

public:
	MoveToPosWithTime(GameObject* gameObject, glm::vec3 pos, float time);

	// Inherited via BaseCommand
	void StartCommand() override;
	void Update() override;
	void EndCommand() override;
	bool IsCommandCompleted() override;

private:

	float time;
	float timeStep = 0;

	glm::vec3 startPos;
	glm::vec3 targetPos;

	GameObject* gameObject;

	
};


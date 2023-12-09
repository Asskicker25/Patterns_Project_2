#pragma once

#include "../CommandManager/BaseCommand.h"

class LookAt : public BaseCommand
{

public:

	LookAt(GameObject* gameObject, GameObject* lookAtObject);

	// Inherited via BaseCommand
	void StartCommand() override;
	void Update() override;
	void EndCommand() override;
	bool IsCommandCompleted() override;

private:

	glm::vec3 diff = glm::vec3(0);
	glm::vec3 dir = glm::vec3(0);
	glm::vec3 right = glm::vec3(0);
	glm::vec3 up = glm::vec3(0);


	GameObject* gameObject;
	GameObject* lookAtObject;
};


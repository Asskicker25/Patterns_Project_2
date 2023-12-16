#pragma once

#include "../CommandManager/BaseCommand.h"

class ChangeColor : public BaseCommand
{

public:

	ChangeColor(BaseMaterial* material, glm::vec3 color);
	ChangeColor(BaseMaterial* material);


private:
	// Inherited via BaseCommand
	void StartCommand() override;
	void Update() override;
	void EndCommand() override;
	bool IsCommandCompleted() override;

	bool colorChanged = false;

	BaseMaterial* material;
	glm::vec3 color; 
};


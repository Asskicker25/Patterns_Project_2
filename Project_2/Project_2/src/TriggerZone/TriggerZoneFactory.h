#pragma once

#include "TriggerZone.h"

class TriggerZoneFactory
{
public:

	TriggerZoneFactory();
	TriggerZone* CreateZone(const std::string& zoneID, const glm::vec3& scale);
	void AssignComponents(Renderer* renderer,  PhysicsEngine* physicsEngine);
	void SetShader(Shader* shader);

private:
	Renderer* renderer;
	Shader* shader;
	PhysicsEngine* physicsEngine;

	Model* zonePlaceHolder;
};


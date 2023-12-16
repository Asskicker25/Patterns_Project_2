#pragma once+

#include "../EntityManager/EntityManager.h"
#include "TriggerZoneFactory.h"

class TriggerZoneManager : public Entity
{

public:

	TriggerZoneFactory* triggerZoneFactory;

	static TriggerZoneManager& GetInstance();

	TriggerZoneManager();

	GameObject* SpawnZone(const std::string& zoneId, const glm::vec3& pos, const glm::vec3& scale);
	void SetShader(Shader* shader);

private:

	Shader* alphaBlendShader;
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;
};


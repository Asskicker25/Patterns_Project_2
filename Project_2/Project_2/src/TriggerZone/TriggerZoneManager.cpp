#include "TriggerZoneManager.h"

TriggerZoneManager& TriggerZoneManager::GetInstance()
{
	static TriggerZoneManager instance;
	return instance;
}

TriggerZoneManager::TriggerZoneManager()
{
	triggerZoneFactory = new TriggerZoneFactory();

	InitializeEntity(this);
}

GameObject* TriggerZoneManager::SpawnZone(const std::string& zoneId, const glm::vec3& scale)
{
	TriggerZone* zone = triggerZoneFactory->CreateZone(zoneId, scale);
	return zone;
}

void TriggerZoneManager::SetShader(Shader* shader)
{
	this->alphaBlendShader = shader;
	triggerZoneFactory->SetShader(shader);

}

void TriggerZoneManager::Start()
{
}

void TriggerZoneManager::Update(float deltaTime)
{
}

void TriggerZoneManager::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	triggerZoneFactory->AssignComponents(renderer, physicsEngine);
}

void TriggerZoneManager::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

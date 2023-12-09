#include "TriggerZoneFactory.h"
#include "../EntityManager/EntityManager.h"

TriggerZoneFactory::TriggerZoneFactory()
{
	zonePlaceHolder = new Model("res/Models/DefaultCube.fbx");
	zonePlaceHolder->meshes[0]->material->AsMaterial()->SetBaseColor(glm::vec4(0.2, 1.0, 0.2, 0.3));
}

TriggerZone* TriggerZoneFactory::CreateZone(const std::string& zoneID, const glm::vec3& scale)
{
	TriggerZone* zone = new TriggerZone();

	zone->CreateInstance(*zonePlaceHolder);
	zone->tag = zoneID;
	zone->model->transform.SetScale(scale);

	renderer->AddModel(zone->model, shader);
	physicsEngine->AddPhysicsObject(zone->phyObj);

	EntityManager::GetInstance().AddEntity(zoneID, zone);

	return zone;

}

void TriggerZoneFactory::AssignComponents(Renderer* renderer,PhysicsEngine* physicsEngine)
{
	this->renderer = renderer;
	this->physicsEngine = physicsEngine;
}

void TriggerZoneFactory::SetShader(Shader* shader)
{
	this->shader = shader;
}

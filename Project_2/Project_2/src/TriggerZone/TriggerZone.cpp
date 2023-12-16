#include "TriggerZone.h"
#include "../LuaManager/CommandManager/CommandManager.h"


TriggerZone::TriggerZone()
{
	model = new Model();
	phyObj = new PhysicsObject();
}

void TriggerZone::CreateInstance(Model& model)
{
	this->model->CopyFromModel(model);
	phyObj->isEnabled = false;
	phyObj->Initialize(this->model, AABB, DYNAMIC, TRIGGER, true);
	phyObj->userData = this;
}

void TriggerZone::Start()
{
}

void TriggerZone::Update(float deltaTime)
{
	renderer->DrawAABB(GetGraphicsAabb(phyObj->GetModelAABB()));
}

void TriggerZone::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	this->renderer = renderer;
}

void TriggerZone::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

Transform* TriggerZone::GetTransform()
{
	return &model->transform;
}

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
	phyObj->Initialize(this->model, AABB, DYNAMIC, TRIGGER, true);
	phyObj->userData = this;
}

void TriggerZone::Start()
{
}

void TriggerZone::Update(float deltaTime)
{
}

void TriggerZone::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
}

void TriggerZone::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

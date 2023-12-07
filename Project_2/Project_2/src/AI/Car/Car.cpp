#include "Car.h"
#include "../../LuaManager/CommandManager/CommandManager.h"

Car::Car()
{
	model = new Model();
	phyObj = new PhysicsObject();

	entityId = "Car";

	InitializeEntity(this);

	luaState = new LuaState("Car", this);
	luaState->LoadScript("LuaScripts/Car.lua");

	CommandManager::GetInstance().BindGameObject(this);

	luaState->Execute();
}

void Car::Start()
{
}

void Car::Update(float deltaTime)
{
}

void Car::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
}

void Car::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

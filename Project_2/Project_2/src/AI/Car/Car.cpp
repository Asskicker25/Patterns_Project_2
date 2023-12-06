#include "Car.h"

Car::Car()
{
	model = new Model();
	phyObj = new PhysicsObject();

	InitializeEntity(this);

	luaState = new LuaState("Car", model);
	luaState->LoadScript("LuaScripts/Car.lua");
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

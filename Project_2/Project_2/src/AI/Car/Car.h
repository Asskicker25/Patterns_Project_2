#pragma once

#include "../../EntityManager/Entity.h"
#include "../../LuaManager/LuaState.h"
#include "../../GameObject/GameObject.h"

class Car : public GameObject
{

public:

	LuaState* luaState;

	Car();

private:
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;
};


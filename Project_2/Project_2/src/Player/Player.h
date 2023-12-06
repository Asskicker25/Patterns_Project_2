#pragma once

#include "../EntityManager/Entity.h"
#include "../GameObject/GameObject.h"
#include "../LuaManager/LuaState.h"

class Player : public GameObject
{
public:

	LuaState* luaState;

	Player();

private:
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;
};


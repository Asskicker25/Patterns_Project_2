#pragma once

#include "../../LuaManager/LuaState.h"
#include "BaseCar.h"

class Car : public BaseCar
{

public:

	LuaState* luaState;

	Car();
	void CreateInstance(Model& model);
	void LoadLuaScript();

private:
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;

	Renderer* renderer;
};


#pragma once

#include "../../EntityManager/EntityManager.h"
#include "CarFactory.h"
#include "../../LuaManager/LuaState.h"

class CarManager : public GameObject
{
public:
	
	CarFactory* carFactory;
	
	LuaState* luaState;

	static CarManager& GetInstance();

	CarManager();

	void SpawnCar(const std::string& carId, int type = 0);
	void LoadLuaScript();


private:
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;

	// Inherited via GameObject
	Transform* GetTransform() override;
};


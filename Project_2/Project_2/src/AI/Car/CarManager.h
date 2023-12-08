#pragma once

#include "../../EntityManager/EntityManager.h"
#include "CarFactory.h"

class CarManager : public Entity
{
public:
	
	CarFactory* carFactory;

	static CarManager& GetInstance();

	CarManager();

	void SpawnCar(const std::string& carId, int type = 0);


private:
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;
};


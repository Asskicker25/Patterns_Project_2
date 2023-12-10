#pragma once

#include "BaseCar.h"

class CarFactory
{
public:
	CarFactory();
	BaseCar* CreateCar(const std::string& id, int type = 0);
	void AssignComponents(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine);

private:

	Renderer* renderer;
	Shader* shader;
	PhysicsEngine* physicsEngine;

	Model* yellowCar;
	Model* blueCar;
	Model* redCar;

	void CacheCarModels();
};


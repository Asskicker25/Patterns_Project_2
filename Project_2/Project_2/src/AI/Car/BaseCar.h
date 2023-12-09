#pragma once

#include "../../GameObject/GameObject.h"

class BaseCar : public GameObject
{
public:

	~BaseCar() {};

	// Inherited via GameObject
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) = 0;
	virtual void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) = 0;

	// Inherited via GameObject
	Transform* GetTransform() override;
};


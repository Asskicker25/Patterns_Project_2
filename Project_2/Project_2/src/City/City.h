#pragma once

#include "../GameObject/GameObject.h"

class City : public GameObject
{

public:

	City();

private:
	// Inherited via GameObject
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;

	// Inherited via GameObject
	Transform* GetTransform() override;
};


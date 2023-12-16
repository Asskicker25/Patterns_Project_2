#pragma once

#include "../GameObject/GameObject.h"

class TriggerZone : public GameObject
{

public:
	TriggerZone();
	void CreateInstance(Model& model);

	// Inherited via GameObject
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;

	// Inherited via GameObject
	Transform* GetTransform() override;

	Renderer* renderer;
};


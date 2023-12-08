#pragma once

#include "../EntityManager/Entity.h"
#include "../GameObject/GameObject.h"
#include "../LuaManager/LuaState.h"
#include "../Utilities/BezierCurve/CubicBezierCurve.h"
#include "../LuaManager/Commands/FollowCurveWithTime.h"

class Player : public GameObject
{
public:

	LuaState* luaState;
	CubicBezierCurve* bezierPath;
	FollowCurveWithTime* followCurve;

	Player();

private:

	Renderer* renderer;

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine) override;
	void RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine) override;
};


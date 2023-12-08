#pragma once

#include "../CommandManager/BaseCommand.h"
#include "../../Utilities/BezierCurve/CubicBezierCurve.h"
#include "../CommandManager/EaseCommand.h"

class FollowCurveWithTime : public BaseCommand, public EaseCommand
{
public:

	FollowCurveWithTime(GameObject* gameObject, float time);

	// Inherited via BaseCommand
	void StartCommand() override;
	void Update() override;
	void EndCommand() override;
	bool IsCommandCompleted() override;

	void SetBezierCurve(CubicBezierCurve* curve);

private:

	int currentPointIndex = 0;

	float time;
	float lerpTime = 0;
	float lerpValue= 0;
	float timeStep = 0;
	float deltaTime = 0;

	float timeStepCurve = 0;

	glm::vec3 startPos = glm::vec3(0);
	glm::vec3 targetPos = glm::vec3(0);

	GameObject* gameObject;
	CubicBezierCurve* curve = nullptr;

};


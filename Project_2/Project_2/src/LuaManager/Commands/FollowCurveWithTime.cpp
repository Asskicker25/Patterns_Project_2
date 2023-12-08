#include "FollowCurveWithTime.h"
#include "../../Utilities/Lerp.h"


FollowCurveWithTime::FollowCurveWithTime(GameObject* gameObject, float time)
{
	this->gameObject = gameObject;
	this->time = time;
}

void FollowCurveWithTime::StartCommand()
{
	curve->CalculateCurve();

	currentPointIndex = 1;
	lerpTime = time * curve->spacing;

	easeInRatio = easeInTime / time;
	easeOutRatio = easeOutTime / time;

	easeOutStart = 1 - easeOutRatio;

	startPos = curve->GetCachedPointOnCurve(0);
	targetPos = curve->GetCachedPointOnCurve(currentPointIndex);
}

void FollowCurveWithTime::Update()
{
	if (currentPointIndex >= curve->GetCurveCount()) return;

	updatedOnce = true;

	deltaTime = Time::GetInstance().deltaTime;

	timeStep += deltaTime / lerpTime;

	timeStepCurve = timeStep * curve->spacing * currentPointIndex;

	if (time == 0)
	{
		lerpValue = 1;
		timeStep = 1;
	}
	else if (easeInTime != 0 && timeStepCurve <= easeInRatio)
	{

		lerpValue = EaseIn(easeInMode, timeStepCurve / easeInRatio);
		lerpValue *= easeInRatio;
		lerpValue /= (curve->spacing * currentPointIndex);
	}
	else if (easeOutTime != 0 && timeStepCurve >= easeOutStart)
	{
		lerpValue = EaseOut(easeOutMode, (timeStepCurve - easeOutStart) / easeOutRatio);
		lerpValue *= easeOutRatio;
		lerpValue += easeOutStart;
		lerpValue /= (curve->spacing * currentPointIndex);
	}
	else
	{
		lerpValue = timeStep;
	}

	gameObject->model->transform.SetPosition(
		Lerp(startPos, targetPos, lerpValue)
	);

	curve->DrawCurve();
}

void FollowCurveWithTime::EndCommand()
{
}

bool FollowCurveWithTime::IsCommandCompleted()
{
	if (!updatedOnce) return false;

	if (lerpValue >= 1.0f)
	{
		currentPointIndex++;

		if (currentPointIndex >= curve->GetCurveCount())
		{
			return true;
		}

		timeStep = 0;
		lerpValue = 0;
		startPos = targetPos;
		targetPos = curve->GetCachedPointOnCurve(currentPointIndex);
	}

	return false;
}

void FollowCurveWithTime::SetBezierCurve(CubicBezierCurve* curve)
{
	this->curve = curve;
}

#include "FollowObject.h"
#include "../../Utilities/Lerp.h"
#include "../../Utilities/Remap.h"

FollowObject::FollowObject(GameObject* followObject, GameObject* targetObject)
{
	this->followObject = followObject;
	this->targetObject = targetObject;
}

void FollowObject::StartCommand()
{
	timeStep = 0;
	sqDeacceleration = deaccelerationRange * deaccelerationRange;
	sqAcceleration = accelerationRange * accelerationRange;
}

void FollowObject::Update()
{
	deltaTime = Time::GetInstance().deltaTime;

	startPos = followObject->model->transform.position;
	targetPos = targetObject->model->transform.position + followOffset;

	glm::vec3 diff = targetPos - startPos;
	glm::vec3 dir = glm::normalize(diff);

	targetPos -= dir * followDistance;

	diff = targetPos - startPos;
	sqDist = glm::dot(diff, diff);



	float remapedValue;
	if (sqDeacceleration != 0 && sqDist <= sqDeacceleration)
	{
		remapedValue = remap(sqDist, 0, sqDeacceleration, 0, 1);
	}
	else if (sqAcceleration != 0 && sqDist >= sqAcceleration)
	{
		remapedValue = 1;
	}
	else if(sqDeacceleration != 0 && sqAcceleration != 0)
	{
		remapedValue = remap(sqDist, sqDeacceleration, sqAcceleration, 0.5, 1.0f);
	}
	else
	{
		remapedValue = 1;
	}

	timeStep = CalculateTForSpeed(timeStep, deltaTime, maxSpeed * remapedValue);

	followObject->model->transform.SetPosition(
		Lerp(startPos, targetPos, timeStep)
	);
}

void FollowObject::EndCommand()
{
}

bool FollowObject::IsCommandCompleted()
{

	return false;
}

void FollowObject::SetFollowDistance(const float& followDistance)
{
	this->followDistance = followDistance;
}

void FollowObject::SetMaxSpeed(const float& maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void FollowObject::SetFollowOffset(const glm::vec3& offset)
{
	this->followOffset = offset;
}

void FollowObject::SetAccelerationRange(const float& range)
{
	accelerationRange = range;
}

void FollowObject::SetDeaccelerationRange(const float& range)
{
	deaccelerationRange = range;
}

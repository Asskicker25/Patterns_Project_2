#include "MoveWithSpeed.h"
#include "../../Utilities/Lerp.h"

MoveWithSpeed::MoveWithSpeed(GameObject* gameObject, glm::vec3 pos, float speed)
{
	this->speed = speed;
	this->targetPos = pos;
	this->gameObject = gameObject;
}

void MoveWithSpeed::StartCommand()
{
	this->startPos = gameObject->model->transform.position;
	timeStep = 0;
}

void MoveWithSpeed::Update()
{
	timeStep = CalculateTForSpeed(timeStep, Time::GetInstance().deltaTime, speed);

	gameObject->model->transform.SetPosition(
		Lerp(startPos, targetPos, timeStep)
	);
}

void MoveWithSpeed::EndCommand()
{
}

bool MoveWithSpeed::IsCommandCompleted()
{
	if (!updatedOnce) return false;

	if (timeStep >= 1.0f)
	{
		return true;
	}

	return false;
}

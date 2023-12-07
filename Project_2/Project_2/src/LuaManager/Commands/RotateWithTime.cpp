#include "RotateWithTime.h"
#include "../../Utilities/Lerp.h"

RotateWithTime::RotateWithTime(GameObject* gameObject, glm::vec3 rotation, float time)
{
    this->gameObject = gameObject;
    this->targetRotation = rotation;
    this->time = time;
}

void RotateWithTime::StartCommand()
{
    startRotation = gameObject->model->transform.rotation;
    timeStep = 0;
}

void RotateWithTime::Update()
{
    timeStep += Time::GetInstance().deltaTime / time;

    gameObject->model->transform.SetRotation(
        Lerp(startRotation, targetRotation, timeStep)
    );
}

void RotateWithTime::EndCommand()
{
}

bool RotateWithTime::IsCommandCompleted()
{
    if (timeStep >= 1.0f)
    {
        return true;
    }
    return false;
}

#include "MoveToPosWithTime.h"
#include "../../Utilities/Lerp.h"

MoveToPosWithTime::MoveToPosWithTime(GameObject* gameObject, glm::vec3 pos, float time)
{
    this->time = time;
    this->targetPos = pos;
    this->gameObject = gameObject;
}

void MoveToPosWithTime::StartCommand()
{
    this->startPos = gameObject->model->transform.position;
    timeStep = 0;
}

void MoveToPosWithTime::Update()
{
    timeStep += Time::GetInstance().deltaTime / time;


    gameObject->model->transform.SetPosition(
        Lerp(startPos, targetPos, timeStep)
    );

}

void MoveToPosWithTime::EndCommand()
{
}

bool MoveToPosWithTime::IsCommandCompleted()
{
    if (timeStep >= 1.0f)
    {
        return true;
    }

    return false;
}

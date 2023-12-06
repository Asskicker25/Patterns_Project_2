#include "MoveToPosWithTime.h"

MoveToPosWithTime::MoveToPosWithTime(GameObject* gameObject, glm::vec3 pos, float time)
{
    this->gameObject = gameObject;
    this->pos = pos;
    this->time = time;
}

void MoveToPosWithTime::StartCommand()
{
}

void MoveToPosWithTime::Update()
{
}

void MoveToPosWithTime::EndCommand()
{
}

bool MoveToPosWithTime::IsCommandCompleted()
{
    return false;
}

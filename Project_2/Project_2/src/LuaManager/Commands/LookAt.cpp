#include "LookAt.h"

LookAt::LookAt(GameObject* gameObject, GameObject* lookAtObject)
{
    this->gameObject = gameObject;
    this->lookAtObject = lookAtObject;
}

void LookAt::StartCommand()
{
}

void LookAt::Update()
{
    diff = lookAtObject->GetTransform()->position - gameObject->GetTransform()->position;
    dir = glm::normalize(diff);

    right = glm::cross(glm::vec3(0, 1, 0), dir);
    up = glm::cross(dir, right);

    gameObject->GetTransform()->SetOrientationFromDirections(up, right);
}

void LookAt::EndCommand()
{
}

bool LookAt::IsCommandCompleted()
{
    return false;
}

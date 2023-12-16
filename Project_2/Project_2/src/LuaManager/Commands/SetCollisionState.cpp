#include "SetCollisionState.h"

SetCollisionState::SetCollisionState(PhysicsObject* phyObj, bool state)
{
    this->phyObj = phyObj;
    this->state = state;
}

void SetCollisionState::StartCommand()
{
    phyObj->isEnabled = state;
    isStateUpdated = true;
}

void SetCollisionState::Update()
{
}

void SetCollisionState::EndCommand()
{
    isStateUpdated = false;
    inProgress = false;
}

bool SetCollisionState::IsCommandCompleted()
{
    return isStateUpdated;
}

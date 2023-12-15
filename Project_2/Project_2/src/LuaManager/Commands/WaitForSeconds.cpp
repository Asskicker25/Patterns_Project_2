#include "WaitForSeconds.h"

WaitForSeconds::WaitForSeconds(float time)
{
    this->time = time;
}

void WaitForSeconds::StartCommand()
{
    timeStep = 0;
}

void WaitForSeconds::Update()
{
  
    timeStep += Timer::GetInstance().deltaTime;
}

void WaitForSeconds::EndCommand()
{
    timeStep = 0;
    inProgress = false;
}

bool WaitForSeconds::IsCommandCompleted()
{
    if (timeStep >= time)
    {
        return true;
    }
    return false;
}

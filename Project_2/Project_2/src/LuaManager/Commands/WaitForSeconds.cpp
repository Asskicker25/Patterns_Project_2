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
    timeStep += Time::GetInstance().deltaTime;
}

void WaitForSeconds::EndCommand()
{
}

bool WaitForSeconds::IsCommandCompleted()
{
    if (timeStep >= time)
    {
        return true;
    }
    return false;
}

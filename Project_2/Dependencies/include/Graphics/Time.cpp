#include "Time.h"

Time& Time::GetInstance()
{
    static Time instance;
    return instance;
}

void Time::SetCurrentTime(float currentTime)
{
    this->currentTime = currentTime;

    deltaTime = currentTime - lastFrameTime;

    lastFrameTime = currentTime;
}

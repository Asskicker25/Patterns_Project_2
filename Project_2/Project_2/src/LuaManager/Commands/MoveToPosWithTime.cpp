#include "MoveToPosWithTime.h"
#include "../../Utilities/Lerp.h"
#include "../../Utilities/Remap.h"

float startTime = 0;

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

	startTime = Time::GetInstance().currentTime;
}


void MoveToPosWithTime::Update()
{
	float lerpValue;

    if (time == 0)
    {
        timeStep = time;
        lerpValue = 1;
    }
    else
    {
        timeStep += Time::GetInstance().deltaTime;

        if (easeInTime != 0 &&  timeStep <= easeInTime)
        {
            lerpValue = EaseIn(easeInMode ,timeStep / easeInTime);
            lerpValue *= easeInTime / time;
        }
        else if (easeOutTime != 0 && timeStep > time - easeOutTime)
        {
            lerpValue = EaseOut(easeOutMode ,( timeStep - (time - easeOutTime) )/ easeOutTime);
            lerpValue *= easeOutTime / time;
            lerpValue += 1 - (easeOutTime / time);
        }
        else
        {
            lerpValue = timeStep/time;
        }
    }

    gameObject->model->transform.SetPosition(
        Lerp(startPos, targetPos, lerpValue)
    );
}

void MoveToPosWithTime::EndCommand()
{
}

bool MoveToPosWithTime::IsCommandCompleted()
{
	if (!updatedOnce) return false;

	if (timeStep >= time)
	{
		return true;
	}

	return false;
}

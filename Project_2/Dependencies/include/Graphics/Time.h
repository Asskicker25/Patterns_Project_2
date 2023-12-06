#pragma once

class Time
{
public:
	static Time& GetInstance();

	float deltaTime{ 0 };
	float currentTime{ 0 };
	float lastFrameTime{ 0 };

	void SetCurrentTime(float currentTime);

};


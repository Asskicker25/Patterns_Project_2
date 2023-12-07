#pragma once

#include "../../Utilities/EasingHelper.h"

class EaseCommand
{
public:
	float easeInTime = 0;
	float easeOutTime = 0;

	Ease_Mode easeInMode;
	Ease_Mode easeOutMode;
};


#pragma once

#include <glm/glm.hpp>
#include <vector>

class CubicBezierCurve
{
public:
	struct CubicBezierPoint;

	CubicBezierCurve();
	void AddPoint(CubicBezierPoint point);

private:
	std::vector<CubicBezierPoint> listOfPoints;
};


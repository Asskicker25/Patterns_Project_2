#include "CubicBezierCurve.h"

struct CubicBezierCurve::CubicBezierPoint
{
	glm::vec3 point;
	glm::vec3 controlPoint;
};

CubicBezierCurve::CubicBezierCurve()
{
}

void CubicBezierCurve::AddPoint(CubicBezierPoint point)
{
	listOfPoints.push_back(point);
}

#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <Graphics/Renderer.h>

struct CubicBezierPoint
{
	glm::vec3 point;
	glm::vec3 controlPoint;

	CubicBezierPoint(const glm::vec3& point, const glm::vec3& controlPoint)
	{
		this->point = point;
		this->controlPoint = controlPoint;
	}

};

class CubicBezierCurve
{
public:
	
	float spacing = 0;

	CubicBezierCurve(float spacing = 0.01f);

	void CalculateCurve();
	void DrawCurve();

	int GetCurveCount();

	void AddPoint(CubicBezierPoint point);

	glm::vec3 GetCachedPointOnCurve(int index);

private:

	Renderer* renderer;

	bool visualize = true;

	std::vector<CubicBezierPoint> listOfPoints;
	std::vector<glm::vec3> listOfPointsOnCurve;

	glm::vec3 GetPointOnCurve(float t) const;

};


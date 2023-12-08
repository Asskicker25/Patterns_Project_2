#include "CubicBezierCurve.h"
#include <iostream>

CubicBezierCurve::CubicBezierCurve(Renderer* renderer, float spacing)
{
    this->renderer = renderer;
    this->spacing = spacing;
}

void CubicBezierCurve::CalculateCurve()
{
    listOfPointsOnCurve.clear();

    int count = 1 / spacing;

    for (int i = 0; i <= count; i++)
    {
        listOfPointsOnCurve.push_back(GetPointOnCurve(i * spacing));
    }
}

void CubicBezierCurve::DrawCurve()
{
    if (!visualize) return;

    for(glm::vec3 point : listOfPointsOnCurve)
    { 
        renderer->DrawCube(point, glm::vec3(0), glm::vec3(0.1f), glm::vec4(1, 0, 0, 1), false);
    }
}

int CubicBezierCurve::GetCurveCount()
{
    return listOfPointsOnCurve.size();
}

void CubicBezierCurve::AddPoint(CubicBezierPoint point)
{
	listOfPoints.push_back(point);
}

glm::vec3 CubicBezierCurve::GetCachedPointOnCurve(int index)
{
    return listOfPointsOnCurve[index];
}

glm::vec3 CubicBezierCurve::GetPointOnCurve(float t) const
{
    if (listOfPoints.size() < 2) 
    {
        std::cout << "Insufficient points to create a Bezier curve." << std::endl;
        return glm::vec3(0.0f);
    }

    glm::vec3 p0 = listOfPoints[0].point;
    glm::vec3 c0 = listOfPoints[0].controlPoint;

    glm::vec3 p1 = listOfPoints[1].point;
    glm::vec3 c1 = listOfPoints[1].controlPoint;

    // Use De Casteljau's algorithm for cubic Bezier curve
    glm::vec3 q0 = p0 + t * (c0 - p0);
    glm::vec3 q1 = c0 + t * (c1 - c0);
    glm::vec3 q2 = q0 + t * (q1 - q0);

    glm::vec3 r0 = c1 + t * (p1 - c1);
    glm::vec3 r1 = q1 + t * (r0 - q1);
    glm::vec3 r2 = r1 + t * (r0 - r1);

    glm::vec3 pointOnCurve = q2 + t * (r2 - q2);

    return pointOnCurve;
}



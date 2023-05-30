#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(Point center, float radius)
{
	if (radius < 0)
		throw invalid_argument("Radius must be positive!");

	this->radius = radius;
}

/// <summary>
/// Параметризованное уравнение окружности: x(t) = R*cos(t); y(t) = R*sin(t)
/// </summary>
Point Circle::GetPoint(float t) {
	return Point(radius * cos(t), 
				 radius * sin(t),
				 0);
}

/// <summary>
/// Первая производная окружности: x'(t) = -R*sin(t); y'(t) = R*cos(t)
/// </summary>
Vector Circle::FirstDerivative(float t) {
	return Vector(Point(-1 * radius * sin(t),
				 radius * cos(t),
				 0));
}

Curve* Circle::CreateRandom()
{
	center = center.CreateRandomPoint();
	radius = abs(rand());
	return this;
}

void Circle::Print()
{
	cout << "Circle: ";
	Curve::Print();
	cout << ", radius: " << radius;
}

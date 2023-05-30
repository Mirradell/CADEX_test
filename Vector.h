#pragma once
#include "Point.h"

struct Vector
{
public:
	Point from, to;

	Vector();
	Vector(Point to);
	Vector(Point from, Point to);

	void printl();

	~Vector();
};
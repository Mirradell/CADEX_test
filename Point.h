#pragma once
#include <iostream>

struct Point
{
public:
	float x, y, z;

	Point(float x, float y, float z);
	Point(float x, float y);
	Point();

	void print();
	void printl();

	Point CreateRandomPoint();
};
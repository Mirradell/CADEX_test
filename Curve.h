#pragma once

#include "Point.h"
#include "Vector.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Curve
{
public:
	Point center;

	Curve();
	Curve(Point p);

	virtual Point GetPoint(float t);
	virtual Vector FirstDerivative(float t);
	
	virtual Curve* CreateRandom();
	virtual void Print();

	~Curve();
};


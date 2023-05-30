#pragma once
#define _USE_MATH_DEFINES
#include "Circle.h"
class Helix :
    public Circle
{
public:
    float step;

    Helix();
    Helix(Point center, float radius, float step);

    virtual Point GetPoint(float t) override;
    virtual Vector FirstDerivative(float t) override;

    virtual Curve* CreateRandom() override;
    virtual void Print() override;
};


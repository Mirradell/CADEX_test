#pragma once
#include "Curve.h"
class Circle :
    public Curve
{
public:
    float radius;

    Circle();
    Circle(Point center, float radius);

    virtual Point GetPoint(float t) override;
    virtual Vector FirstDerivative(float t) override;

    virtual Curve* CreateRandom() override;
    virtual void Print() override;
};


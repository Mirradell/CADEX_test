#pragma once
#include "Curve.h"
class Ellipse :
    public Curve
{
public:
    float radiusX, radiusY;

    Ellipse();
    Ellipse(Point center);
    Ellipse(Point center, float radiusX, float radiusY);

    virtual Point GetPoint(float t) override;
    virtual Vector FirstDerivative(float t) override;

    virtual Curve* CreateRandom() override;
    virtual void Print() override;
};


#include "Vector.h"

Vector::Vector() : Vector(Point(), Point())
{ }

Vector::Vector(Point to) : Vector(Point(), to)
{ }

Vector::Vector(Point from, Point to)
{
	this->from = from;
	this->to = to;
}

void Vector::printl()
{
	std::cout << "Vector from ";
	from.print();
	std::cout << " to ";
	to.printl();
}

Vector::~Vector()
{ }

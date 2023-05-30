#include <format>
#include "Point.h"

Point::Point(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(float x, float y) : Point(x, y, 0) 
{ }

Point::Point() : Point(0, 0, 0) 
{ }

void Point::print() {
	std::cout << std::format("({0}, {1}, {2})", x, y, z);
}

void Point::printl() {
	print();
	std::cout << std::endl;
}

Point Point::CreateRandomPoint()
{
	return Point(rand(), rand(), rand());
}

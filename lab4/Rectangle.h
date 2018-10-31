#ifndef RECTANGLE
#define RECTANGLE
#include "TwoDimensionalShape.cpp"
class Rectangle: public TwoDimensionalShape{
	public:
		Rectangle(double length = 0, double width = 0);
		virtual double getArea();
};
#endif

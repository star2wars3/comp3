#ifndef CIRCLE
#define CIRCLE
#include "TwoDimensionalShape.cpp"
class Circle: public TwoDimensionalShape{
	public:
		Circle(double radius = 0);
		virtual double getArea();
};
#endif

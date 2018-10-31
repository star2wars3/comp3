#ifndef TRIANGLE
#define TRIANGLE
#include "TwoDimensionalShape.cpp"
class Triangle: public TwoDimensionalShape{
	public:
		Triangle(double base_ = 0, double height_ = 0);
		virtual double getArea();
};
#endif

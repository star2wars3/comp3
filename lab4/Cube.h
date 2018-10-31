#ifndef CUBE
#define CUBE
#include "ThreeDimensionalShape.cpp"
class Cube: public ThreeDimensionalShape{
	public:
		Cube(double sideLength = 0);
		virtual double getArea();
		virtual double getVolume();
};
#endif

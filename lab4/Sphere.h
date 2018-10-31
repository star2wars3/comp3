#ifndef SPHERE
#define SPHERE
#include "ThreeDimensionalShape.cpp"
class Sphere: public ThreeDimensionalShape{
	public:
		Sphere(double radius = 0);
		virtual double getArea();
		virtual double getVolume();
};
#endif

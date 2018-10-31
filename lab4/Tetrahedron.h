#ifndef TETRAHEDRON
#define TETRAHEDRON
#include "ThreeDimensionalShape.cpp"
class Tetrahedron: public ThreeDimensionalShape{
	public:
		Tetrahedron(double sideLength = 0);
		virtual double getArea();
		virtual double getVolume();
};
#endif

#include "Tetrahedron.h"
Tetrahedron::Tetrahedron(double sideLength)
	:ThreeDimensionalShape("Tetrahedron",sideLength){}
double Tetrahedron::getArea(){
	return length * length * sqrt(3);
}
double Tetrahedron::getVolume(){
	double aCubed = length * length * length;
	const double divBy = 6 * sqrt(2);
	return aCubed / divBy;
}


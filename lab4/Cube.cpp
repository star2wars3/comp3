#include "Cube.h"
Cube::Cube(double sideLength)
	:ThreeDimensionalShape("CUBE",sideLength){}
double Cube::getArea(){
	const int numSides = 6;
	return numSides * length * length;
}
double Cube::getVolume(){
	return length * length * length;
}

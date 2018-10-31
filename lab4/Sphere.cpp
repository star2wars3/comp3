#include "Sphere.h"
Sphere::Sphere(double radius)
	:ThreeDimensionalShape("SPHERE",radius){}
double Sphere::getArea(){
	return 4* length * length * M_PI;
}
double Sphere::getVolume(){
	double rCubed = length * length * length;
	return (4.0 / 3) * M_PI * rCubed;
}

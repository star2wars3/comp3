#include "Triangle.h"
Triangle::Triangle(double base, double height)
	:TwoDimensionalShape("TRIANGLE",base,height){}
double Triangle::getArea(){
	return base * height/2;
}


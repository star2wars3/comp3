#include "Circle.h"
Circle::Circle(double radius)
	:TwoDimensionalShape("CIRCLE",radius,radius){}
double Circle::getArea(){
	return 2 * base * M_PI;//for circle radius = 2 * pi * radius
}


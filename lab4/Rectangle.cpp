#include "Rectangle.h"
Rectangle::Rectangle(double length, double width)
	:TwoDimensionalShape("RECTANGLE",length,width){}
double Rectangle::getArea(){
	return base * height;
}


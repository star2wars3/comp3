#ifndef TWO_DIMENSIONAL_SHAPE_CPP
#define TWO_DIMENSIONAL_SHAPE_CPP
#include "TwoDimensionalShape.h"
TwoDimensionalShape::TwoDimensionalShape(std::string name)
	:Shape(name,"2D_SHAPE"),base(0),height(0){}
TwoDimensionalShape::TwoDimensionalShape(std::string name, double width, double height)
	:Shape(name,"2D_SHAPE"),base(width),height(height){
	if (base < 0){
		base = 0;
	}
	if (height < 0){
		height = 0;
	}
}
double TwoDimensionalShape::getArea(){
	return 0;
}
#endif

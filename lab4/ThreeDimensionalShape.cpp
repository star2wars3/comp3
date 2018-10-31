#ifndef THREE_DIMENSIONAL_SHAPE_CPP
#define THREE_DIMENSIONAL_SHAPE_CPP
#include "ThreeDimensionalShape.h"
ThreeDimensionalShape::ThreeDimensionalShape(std::string name)
	:Shape(name,"3D_SHAPE"),length(0){}

ThreeDimensionalShape::ThreeDimensionalShape(std::string name, double length_)
	:Shape(name,"3D_SHAPE"),length(length_){
	if (length < 0){
		length = 0;
	}
}

double ThreeDimensionalShape::getArea(){
	return 0;
}

double ThreeDimensionalShape::getVolume(){
	return 0;
}
#endif

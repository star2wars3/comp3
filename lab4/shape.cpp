#ifndef SHAPE_CPP
#define SHAPE_CPP
#include "shape.h"
Shape::Shape():name("SHAPE"),type("SHAPE"){}
Shape::Shape(std::string name_, std::string type_):name(name_),type(type_){}
double Shape::getArea(){
	return 0;
}
double Shape::getVolume(){
	return 0;
}
std::string Shape::getName(){
	return name;
}
std::string Shape::getType(){
	return type;
}
#endif

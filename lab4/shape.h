#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <cmath>
//using std::std::string;
class Shape{
protected:
	const std::string name;
	const std::string type;
	Shape(std::string name_, std::string type_);
public:
	Shape();
	
	virtual double getArea();
	virtual double getVolume();
	std::string getName();
	std::string getType();
};
#endif

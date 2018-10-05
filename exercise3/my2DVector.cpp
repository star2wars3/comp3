/*
Aaron Milgram
my2DVector.cpp
4 Oct, 2018

*/


//2d_vector
//add
//subtract
//cosine
//scalar_product
//multiply_by_scalar
//do for n-d vectors n > 2
#include "my2DVector.h"
myVector::myVector()
	:dims{0,0}
	{}
myVector::myVector(double x, double y)
	:dims{x,y}
	{}
myVector myVector::add(myVector vector){
	myVector v;
	if (vector.getX() >= -getX() && vector.getY() >= -getY()){
		v.setX(getX() + vector.getX());
		v.setY(getY() + vector.getY());
	}
	return v;	
}
myVector myVector::subtract(myVector vector){
	myVector v;
	if (vector.getX() <= getX() && vector.getY() <= getY()){
		v.setX(getX() - vector.getX());
		v.setY(getY() - vector.getY());
	}
	return v;
}
double myVector::cosine(){
	double hyp = (dims[0]*dims[0]) + (dims[1]*dims[1]);
	hyp = std::sqrt(hyp);
	
	return dims[0] / hyp;
}
double myVector::scalar_product(myVector vector){
	return getX() * vector.getX() + getY() * vector.getY();
}
myVector myVector::multiply_by_scalar(double scalar){
	myVector v;
	if (scalar >= 0){
		v.setX(getX()*scalar);
		v.setY(getY()*scalar);
	}
	return v;
}
double myVector::getX(){
	return dims[0];
}
double myVector::getY(){
	return dims[1];
}
void myVector::setX(double x){
	if (x >= 0){
		dims[0] = x;
	}
}
void myVector::setY(double y){
	if (y >= 0){
		dims[1] = y;
	}
}





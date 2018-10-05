/*
Aaron Milgram
my2DVector.cpp
4 Oct, 2018

*/
#include <iostream>
#include <cmath>
class myVector{
	private:
		double dims[2];
	public:
		myVector();
		myVector(double x, double y);
		myVector add(myVector vector);
		myVector subtract(myVector vector);
		double cosine();
		double scalar_product(myVector vector);
		myVector multiply_by_scalar(double scalar);
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
};

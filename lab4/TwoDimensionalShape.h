#ifndef TWO_DIMENSIONAL_SHAPE
#define TWO_DIMENSIONAL_SHAPE
#include "shape.cpp"
class TwoDimensionalShape: public Shape{
	protected:
		double base;
		double height;
	public:
		TwoDimensionalShape(std::string name = "2D_SHAPE");
		TwoDimensionalShape(std::string name = "2D_SHAPE", double width = 0, double height = 0);
		virtual double getArea();

};
#endif

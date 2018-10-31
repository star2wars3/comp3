#ifndef THREE_DIMENSIONAL_SHAPE
#define THREE_DIMENSIONAL_SHAPE
#include "shape.cpp"
class ThreeDimensionalShape: public Shape{
	protected:
		double length;
	public:
		ThreeDimensionalShape(std::string name = "3D_SHAPE");
		ThreeDimensionalShape(std::string name = "3D_SHAPE", double length_ = 0);
		virtual double getArea();
		virtual double getVolume();
};
#endif

/*
By: Aaron Milgram
Class: Computing 3
Project: Lab4:Shape
Date Due: 30 October 2018
*/
#include "Circle.cpp"
#include "Triangle.cpp"
#include "Rectangle.cpp"
#include "Cube.cpp"
#include "Sphere.cpp"
#include "Tetrahedron.cpp"

int main(){
	int numElements = 7;
	Shape *shapes[numElements] = {new Shape(),new Circle(5),new Triangle(3,6),new Rectangle(3,6),new Cube(3),new Sphere(3),new Tetrahedron(3)};
	for (int i = 0; i < numElements; i++){
		std::cout << (*shapes[i]).getType() << ":";
		std::cout << (*shapes[i]).getName() << std::endl;
		
		if ((*shapes[i]).getType() == "2D_SHAPE"){
			std::cout << "	AREA        : " << (*shapes[i]).getArea() << std::endl;
		}
		else if ((*shapes[i]).getType() == "3D_SHAPE"){
			std::cout << "	SURFACE_AREA: " << (*shapes[i]).getArea() << std::endl;
			std::cout << "	VOLUME      : " << (*shapes[i]).getVolume() << std::endl;
		}
		delete shapes[i];
	}
	return 0;
}

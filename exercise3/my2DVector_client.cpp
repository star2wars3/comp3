#include "my2DVector.cpp"
void print(myVector vector);
int main(){
	myVector x(5.0,10.0);
	myVector y;
	myVector z(1.0,1.0);//cos = .707
	myVector w = x.add(z);//x+z
	myVector v = x.subtract(z);//x-z
	myVector u = x.multiply_by_scalar(10);//x*10 = <50,100>

	print(x);
	print(y);
	std::cout << z.cosine() << std::endl;//cos <1.0,1.0>
	print(w);
	print(v);
	print(u);
	std::cout << z.scalar_product(x)<<std::endl;
	return 0;
}

void print(myVector vector){
	std::cout << vector.getX() << ":" << vector.getY() << std::endl;
}

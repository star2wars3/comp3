#include "MyDynArray.cpp"
int main(){
	MyDynArray a(-2);
	MyDynArray b;
	for (int i = 0; i < b.getSize(); i++){
		b.set(i,i);
	}
	for (int i = 0; i < b.getSize(); i++){
		std::cout << b.get(i) << ':' << b.getPtr()[i] << " ";
		if ((i + 1) % 10 == 0){
			std::cout << std::endl;
		}
	}
	a.set(10,5);
	
	
	
	b = a = a;
	bool equal = (b.get(5) == a.get(5));
	std::cout << "arrays set equal to each other have the same values until changed: ";
	std::cout << equal << std::endl;
	
	MyDynArray c(b);
	std::cout << "C Before:\n";
	for (int i = 0; i < c.getSize(); i++){
		 std::cout << c.get(i);
	}
	std::cout << "C After Adding Element\n";
	c.set(44,3);
	for (int i = 0; i < c.getSize(); i++){
		std::cout << c.get(i);
	}
	return 0;
}

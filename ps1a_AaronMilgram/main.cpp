#include "test.cpp"
//more just a temp file until I get boost working 
//rather than an actual test program
//it mirrors the tests used within the provided boost test
int main(){
	LFSR l("00111", 2);
	std::cout << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl;
	std::cout << l.step() << " " << l << std::endl << std::endl;
	LFSR l2("00111", 2);
	std::cout << l2 << std::endl;

	std::cout << l2.generate(8) << std::endl;
return 0;
}

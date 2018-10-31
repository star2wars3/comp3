#include <iostream>
#include <string>
class Polynomial{
	private:
		int size;
		int* terms;
	public:
		Polynomial();
		Polynomial(int* terms, int numTerms);
		~Polynomial();
		Polynomial &operator=(Polynomial arg);
		Polynomial operator+(Polynomial& arg);
		Polynomial &operator+=(Polynomial& arg);
		Polynomial operator-(Polynomial& arg);
		Polynomial &operator-=(Polynomial& arg);
		Polynomial operator*(Polynomial& arg);
		Polynomial &operator*=(Polynomial& arg);
		std::string toString();
		void setSize(int size_);
		void set(int i, int value);
		int getSize();
		int getAt(int i);
};

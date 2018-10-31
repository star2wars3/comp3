#include "Polynomial.h"
Polynomial::Polynomial():size(0),terms(NULL){}

Polynomial::Polynomial(int* terms_, int numTerms):size(numTerms){
	if (getSize() < 0){
		size = 0;
	}
	terms = new int[getSize()];
	for (int i = 0; i < getSize(); ++i){
		terms[i] = terms_[i]; 
	}
}
Polynomial::~Polynomial(){
	delete[] terms;
}
Polynomial& Polynomial::operator=(Polynomial arg){
	int *temp = new int[arg.getSize()];
	if (temp != NULL){
		size = arg.getSize();
		for (int i = size-1; i >= 0; --i){
			temp[i] = arg.getAt(i); 
		}
		if (terms != NULL){
			delete[] terms;
		}
		terms = temp;
	}
	//std::cout <<"[" << arg.toString() << "]"<<std::endl;
	return *this;
}
//overloads the + function
Polynomial Polynomial::operator+(Polynomial& arg){
	Polynomial p;
	std::string larger;
	if (getSize() > arg.getSize()){
		p.setSize(getSize());
		larger = "THIS";
	}
	else {
		p.setSize(arg.getSize());
		larger = "ARG";
	}
	if (larger == "THIS"){
		for (int i = 0; i < p.getSize(); i++){
			if (i < arg.getSize()){
				p.set(i,getAt(i) + arg.getAt(i));
			}
			else{
				p.set(i,getAt(i));
			}
		}
	}
	else{
		for (int i = 0; i < p.getSize(); i++){
			if (i < getSize()){
				p.set(i,getAt(i) + arg.getAt(i));
			}
			else{
				p.set(i,arg.getAt(i));
			}
		}
	}
	return p;
}
Polynomial& Polynomial::operator+=(Polynomial& arg){
	Polynomial p;
	for (int i = getSize()-1; i >= 0; --i){
		p.set(i,getAt(i));
	}
	p = p + arg;
	for (int i = p.getSize()-1; i >= 0; --i){
		set(i,p.getAt(i));
	}
	return *this;
}
Polynomial Polynomial::operator-(Polynomial& arg){
	Polynomial negArg, p;
	for (int i = arg.getSize()-1; i >= 0; --i){
		negArg.set(i,-(arg.getAt(i)));
	}
	for (int i = p.getSize()-1; i >= 0; --i){
		p.set(i,getAt(i));
	}
	p += negArg;
	return p;
	
}
Polynomial& Polynomial::operator-=(Polynomial& arg){
	Polynomial p;
	for (int i = getSize()-1; i >= 0; --i){
		p.set(i,getAt(i));
	}
	p = p + arg;
	for (int i = p.getSize()-1; i >= 0; --i){
		set(i,getAt(i));
	}
	return *this;
}
Polynomial Polynomial::operator*(Polynomial& arg){
	Polynomial p;
	if (getSize() < 0 || arg.getSize() < 0){
		return *this;
	}
	int newSize = getSize() + arg.getSize();
	p.setSize(newSize);
	for (int i = 0; i < getSize(); ++i){
		for (int j = 0; j < arg.getSize(); ++j){
			int tempSize = i + j;
			p.set(tempSize,p.getAt(tempSize) + (getAt(i) * arg.getAt(j)));
		}
	}
	for (int i = p.getSize(); i >= 0; --i){
		set(i,p.getAt(i));
	}
	return p;
}
Polynomial& Polynomial::operator*=(Polynomial& arg){
	Polynomial p;
	for (int i = getSize()-1; i >= 0; --i){
		p.set(i,getAt(i));
	}
	p = p * arg;
	for (int i = p.getSize()-1; i >= 0; --i){
		set(i,getAt(i));
	}
	return *this;
}
std::string Polynomial::toString(){
	std::string str = "";
	if (terms != NULL){
		for (int i = getSize()-1; i >= 0; --i){
			str += std::to_string(getAt(i)) + "x^" + std::to_string(i);
			if (i > 0){
				str += " + ";
			}
		}
	}
	else{
		str += "Null";
	}
	return str;
}

int Polynomial::getSize(){
	return size;
}
int Polynomial::getAt(int i){
	if (i >= 0 && i < getSize()){
		return terms[i];
	}
	return 0;
}
//resizes a polynomial
void Polynomial::setSize(int size_){
	if (size < 0){
		return;
	}
	int *terms_ =  new int[size_];
	for (int i = 0; i < size_; ++i){
		if (i < getSize()){
			terms_[i] = terms[i];
		}
		else{
			terms_[i] = 0;
		}
	}
	if (terms != NULL){
		delete[] terms;
	}
	terms = terms_;
	size = size_;
}
void Polynomial::set(int i, int value){
	if (i >= size){
		setSize(i+1);
	}
	if (i >= 0){
		terms[i] = value;
		//std::cout <<"["<< terms[i] <<":" <<value << "]\n";
	}
}

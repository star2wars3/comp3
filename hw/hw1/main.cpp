/*
 *Author: Aaron Milgram
 *Class: Computing 3 Hon
 *Date: 16 Sept, 2018
 */
#include <iostream>
#include <cmath>

void printArgs(int argc, char* argv[]);
void factorialLoop();
long long int factorial(int number);
void exponent();

int main(int argc, char* argv[]){
	printArgs(argc, argv);	//Question 2
	factorialLoop();		//Question 3, 4
	exponent();				//Question 5
	return 0;
}

//Prints the first argc arguments from argv onto seperate lines
void printArgs(int argc, char* argv[]){
	for (int i = 0; i < argc; i++){
		std::cout << argv[i] << std::endl;
	}
}

//repeatedly prompts the user to enter in a number and outputs its factorial
void factorialLoop(){
	char again = 'y';	
	long long int number = -1;
	bool fail = 0;
	while(again != 'n' && again != 'N'){
		std::cout << "Enter a number and I will output it's factorial: ";
		std::cin >> number;
		fail = std::cin.fail();
		//std::cin.clear();
		//std::cin.ignore(256,'\n');
		while (number < 0 || fail){
			if (fail){
				std::cout << "That wasn't even a number. Try Again: ";	
				fail = 0;
			}
			else{
				std::cout << "Number must be positive or zero. Try Again: ";	
			}
			std::cin.clear();
			std::cin.ignore(256,'\n');
			
			std::cin >> number;
			fail = std::cin.fail();
		}
		std::cout << number << "! = " << factorial(number) << std::endl;
		std::cout << "Again? <y/n>: ";
		std::cin >> again;
		while (again != 'y' && again != 'Y' && again != 'n' && again != 'N'){
			std::cout << "I don't understand. Please enter <y/n>: ";
			std::cin >> again;
		}
		 
		
	}
}

//returns the factorial of the input number
long long int factorial(int number){
	int counter = number;
	long long int value = 1;
	for (; counter > 1; counter--){
		value *= counter;
	}
	return value;
}



//The user inputs a base and an exponent and the program prints
//base^exponent
void exponent(){
	double base;
	double exponent;
	bool fail = 0;
	std::cout << "Enter a number: ";
	std::cin >> base;
	fail = std::cin.fail();
	while (fail){
		std::cout << "That wasn't even a number. Try Again: ";	
		fail = 0;
		std::cin.clear();
		std::cin.ignore(256,'\n');		
		std::cin >> base;
		fail = std::cin.fail();
	}
	std::cout << "Enter another number: ";
	std::cin >> exponent;
	fail = std::cin.fail();
	while (fail){
		std::cout << "That wasn't even a number. Try Again: ";	
		fail = 0;
		std::cin.clear();
		std::cin.ignore(256,'\n');		
		std::cin >> exponent;
		fail = std::cin.fail();
	}
	std::cout << base << "^" << exponent << " = " << pow(base,exponent) 
			  << std::endl;
}









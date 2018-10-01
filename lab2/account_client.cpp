/*
account_client.cpp
Aaron Milgram
2 October, 2018
*/
#include "account.cpp"

int main(int argc, char* argv[]){
	//constant variable to hold the value to init account b with
	const double initAmount = 100; 
	//variable to be used for user input
	double withdraw;
	
	//initialize accounts a and b
	Account a;
	Account b = Account(initAmount);
	
	//withdrawing from an account with no money
	std::cout << "Enter the amount to withdraw from Account a: ";
	std::cin >> withdraw;
	a.debit(withdraw);	
	std::cout << "a:" << a.getBalance()<<std::endl;
	
	//withdrawing from an account with some money
	std::cout << "Enter the amount to withdraw from Account b: ";
	std::cin >> withdraw;
	b.debit(withdraw);	
	std::cout << "b:" << b.getBalance()<<std::endl;
	
	//deposit money in account a
	std::cout << "Enter the amount to deposit to Account a: ";
	std::cin >> withdraw;
	a.credit(withdraw);	
	std::cout << "a:" << a.getBalance()<<std::endl;
	
	//deposit money into account b
	std::cout << "Enter the amount to deposit to Account b: ";
	std::cin >> withdraw;
	b.credit(withdraw);	
	std::cout << "b:" << b.getBalance()<<std::endl;
	
	//print the sum of your account balances
	std::cout << "In total you have $" << a.addAccountBalance(a, b)
			<< std::endl;
	return 0;
}

/*
account.cpp
Aaron Milgram
2 October, 2018
*/
#include "account.h"
//sets the balance to 0
Account::Account(){
	balance = 0;
}

//if balance is positive sets account to balance
//else sets the balance to 0
Account::Account(double balance){
	Account();
	credit(balance);
}
//returns the balance
double Account::getBalance(){
	return balance;
}
//if amount input is positive, adds the given amount to balance
//returns TRUE if successful and FALSE otherwise
bool Account::credit(double amount){
	bool isValidAmount = (amount >= 0);
	if (isValidAmount){
		balance += amount;
	}
	return isValidAmount;
}
//if amount input is positive and amount is smaller than balance 
//decreases balance by amount
//if amount is greater than balance
//prints out "Debit amount exceeded account balance."
//returns TRUE if withdrawal is successful and FALSE otherwise
bool Account::debit(double amount){
	bool isValidAmount = (amount >= 0);
	if (isValidAmount){
		isValidAmount = (amount <= getBalance());
		if (isValidAmount){
			balance -= amount;
		}
		else{
			std::cout << "Debit amount exceeded account balance.\n";
		}	
	
	}
	return isValidAmount;
}
//returns the sum of the balances of accounts a and b
double Account::addAccountBalance(Account a, Account b){
	return a.getBalance() + b.getBalance();
}

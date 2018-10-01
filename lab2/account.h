/*
account.h
Aaron Milgram
2 October, 2018
*/
#ifndef ACCOUNT_H
#define ACOUNT_H
#include <iostream>
class Account{
	private:
		double balance;//how much money you have
	public:
		Account();
		Account(double balance);
		double getBalance();
		bool credit(double amount);
		bool debit(double amount);
		double addAccountBalance(Account a, Account b);


};
#endif

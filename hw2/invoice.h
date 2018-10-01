/*
invoice.h
Aaron Milgram
2 October, 2018
*/
#ifndef INVOICE_H
#define INVOICE_H
#include <iostream>
using std::string;
class Invoice{
	private:
		string partNumber;//number of the part
		string partDescription;//description of the part
		int quantity;//quantity of items
		double price;//price per item
	public:
		Invoice();
		Invoice(string partNumber, string partDescription, 
				int quantity, double price);
		void setPartNumber(string partNumber);
		void setPartDescription(string partDescription);
		void setQuantity(double quantity);
		void setPrice(double price);
		
		string getPartNumber();
		string getPartDescription();
		int    getQuantity();
		double getPrice();
		double getInvoiceAmount();

};
#endif

/*
invoice.cpp
Aaron Milgram
2 October, 2018
*/
#include "invoice.h"

//sets invoice part number and description to empty strings
//all other values set to 0
Invoice::Invoice(){
	setPartNumber("");
	setPartDescription("");
	setQuantity(0);
	setPrice(0);
}

//sets values of invoice to those given	
Invoice::Invoice(string partNumber, string partDescription, 
				int quantity, double price){
	setPartNumber(partNumber);
	setPartDescription(partDescription);
	setQuantity(quantity);
	setPrice(price);			
				
}

//sets invoice partNumber to the input given
void Invoice::setPartNumber(string partNumber){
	Invoice::partNumber = partNumber;
}

//sets invoice partDescription to the input given
void Invoice::setPartDescription(string partDescription){
	Invoice::partDescription = partDescription;
}
//sets invoice quantity to the input given
void Invoice::setQuantity(double quantity){
	Invoice::quantity = quantity;
}
//sets invoice price per unit to the input given
void Invoice::setPrice(double price){
	Invoice::price = price;
}

//returns the partNumber	
string Invoice::getPartNumber(){
	return partNumber;
}
//returns the partDescription
string Invoice::getPartDescription(){
	return partDescription;
}
//returns the quantity
int    Invoice::getQuantity(){
	return quantity;
}
//returns the price per unit
double Invoice::getPrice(){
	return price;
}
//if quantity or price per unit are less than 0, returns 0
//if not, returns the product of the quantity and the price per unit
double Invoice::getInvoiceAmount(){
	double invoice = 0;
	if (getQuantity() > 0 && getPrice() > 0){
		invoice = getQuantity() * getPrice();
	}
	return invoice;
}

/*
invoice_client.cpp
Aaron Milgram
2 October, 2018
*/


#include "invoice.cpp"
void print(Invoice invoice, char c);
int main(int argc, char* argv[]){
	//starting invoice data
	const string initPartNumber      = "1234567890";
	const string initPartDescription = "foo bar";
	const int    initQuantity        = 5;
	const double initPrice           = 5.3;
	// chars used in printing so the user can tell what invoice is being printed
	const char invoiceCharA = 'a';
	const char invoiceCharB = 'b';
	
	
	//initialization
	Invoice a = Invoice(initPartNumber, initPartDescription, 
			initQuantity, initPrice);
	Invoice b;
	print(a, invoiceCharA);
	print(b, invoiceCharB);
	//test for negative quantity
	a.setQuantity(-initQuantity);
	print(a, invoiceCharA);
	//test for negative price
	a.setQuantity(initQuantity);
	a.setPrice(-initPrice);
	print(a, invoiceCharA);
	//test that remaining setters (those not yet tested) work
	b.setPartNumber(initPartDescription);
	b.setPartDescription(initPartNumber);
	print(b, invoiceCharB);
	return 0;
}

//prints results of all getter functions with invoice in a clean readable format
void print(Invoice invoice, char c){
	std::cout << "INVOICE: " << c << std::endl;
	std::cout << "partNumber:       " << invoice.getPartNumber() << std::endl;
	std::cout << "partDescription:  " << 
			invoice.getPartDescription() << std::endl;
	std::cout << "quantity:         " << invoice.getQuantity() << std::endl;
	std::cout << "price:            " << invoice.getPrice() << std::endl;
	std::cout << "total:            " << invoice.getInvoiceAmount() << 
			std::endl << std::endl;
}

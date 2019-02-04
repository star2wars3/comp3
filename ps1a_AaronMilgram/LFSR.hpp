#ifndef LFSR_H
#define LFSR_H
#include <vector>
#include <iostream>
class LFSR {
public: 
	LFSR(std::string seed, int t); 
		// constructor to create LFSR with  
		// the given initial seed and tap 
	int step();                
		// simulate one step and return the 
		// new bit as 0 or 1 
	int generate(int k);  
		// simulate k steps and return  
		// k-bit integer 
	int getTap();
		//returns the tap
	int getLFSR();
		//returns the int value of the LSFR
	friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);
		//prints the int value of the LFSR into the ostream
private:
	std::vector<bool> bits;
	int tap;
};
#endif

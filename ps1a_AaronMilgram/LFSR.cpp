#include "LFSR.hpp"
#include <cmath>
LFSR::LFSR(std::string seed, int t){
	//check that tap is in range of seed and set tap 0 if fail
	if (tap >= (int) seed.size() || tap < 0){
		tap = t;
	}
	else{
		tap = 0;
	}
	//init vector values
	for (int i = 0; i < (int) seed.size(); ++i){
		bits.push_back(seed[i] != '0');
	}
}


// simulate one step and return the 
// new bit as 0 or 1 	 
int LFSR::step(){
	//returns 0 if initial string length is 0
	if ((int)bits.size() < 1){
		return 0;
	}
	//get the new bit
	bool newBit = bits[0] ^ bits[tap];
	//std::cout << "[" << bits[0] << "," << bits[tap] << "]\n";
	//std::cout << "[" << 0 << "," << tap << "]\n";
	//then shift everything over
	int j = 0;
	for (; j < (int) bits.size()-1; ++j){
		bits[j] = bits[j+1];
	}
	bits[j] = newBit;
	//finally return the new bit
	return (int) newBit;
}  





           
// simulate k steps and return  
// k-bit integer 	
int LFSR::generate(int k){
	int i = 0;
	int value = 0;
	int currBit = 0;
	//returns 0 if initial string length is 0
	if ((int)bits.size() < 1){
		return 0;
	}
	//call step k times
	for (;i < k; ++i){
		currBit = step();//value calculated by for each bit double value
		value *= 2;//then add that bit (0 or 1) to the value
		value += currBit;
	}
	//return the generated value
	return value;
}  


//returns the tap
int LFSR::getTap(){
	return tap;
}
	
//returns the int value of the LSFR
//values stored with the nine being at the 0th index in the example here
//that said values are bools unerneath, not ints
//out<9876T3210<in
int LFSR::getLFSR(){
	int value = 0;
	for (int i = 0; i < (int) bits.size(); ++i){
		if (bits[i]){
			value += std::pow(2,(bits.size()-(i+1)));
		}
	}
	return value;
}




//prints the int value of the LFSR into the ostream
std::ostream& operator<< (std::ostream &out, LFSR &lfsr){
	out << lfsr.getLFSR();
	return out;
}

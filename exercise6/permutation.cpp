/*
	Aaron Milgram
	Permutations
	6 December, 2018
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

void print(vector<string> str){
	for (int i = 0; i < str.size(); ++i){
		cout << str.at(i) << " ";
	}
	cout << endl;
}

vector<vector<string>> generate_permutations(vector<string> strings){
	vector<string> v = strings;
	vector<vector<string>> permutations;
	sort(v.begin(),v.end());
	permutations.push_back(v);
	while (next_permutation(v.begin(),v.end())){
		permutations.push_back(v);
	}
	return permutations;
}
int main(int argc, char *argv[]) 
{ 
  // read in strings from stdin 
  	string elt;
  	getline(cin, elt);
  	istringstream strStream(elt);
  	vector<string> elementVector(istream_iterator<string>{strStream}, 
  		istream_iterator<string>());

  	auto permutations = generate_permutations(elementVector); 
  // print permutations to stdout 
  	int count = 0; 
  	cout << endl;
  	for (auto elt : permutations) { 
  	  	cout << ++count << ". "; 
  		print(elt); 
  	}  
} 

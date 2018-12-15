#include "coord.cpp"
#include <algorithm>
#include <iterator>
#include <sstream>
const int requiredArgCount = 2;
int main(int argc, char* argv[]){
	Clusterer<Coord> clusterPoints;
	vector<double> v;
	int length = -1;
	bool success = true;
	string inString;
	
	


//Error program input + error detection
	int numClusters = 2;//atoi(argv[1]);
	if (numClusters < 0){
		cerr << "ERROR: Please use non-nagative command line argument" << endl;
		exit(1);
	}
	do{
		getline(cin, inString);
		success = (!cin.eof() && !cin.fail());
		if (success){
			istringstream strStream(inString);
  			vector<string> elementVector(istream_iterator<string>{strStream}, istream_iterator<string>());
  			if (elementVector.at(0) == "done"){
  				break;
  			}
			if (length < 0){
				length = elementVector.size();
			}
			else if (length != elementVector.size()){
				cerr << "ERROR: All clusters must have an equal number of points" << endl;
				exit(1);
			}
			for (int i = 0; i < elementVector.size(); ++i){
				string s = elementVector.at(i);
				stringstream s2;
				s2 << s;
				double getNum;
				s2 >> getNum;
				v.push_back(getNum);
			}
		}
		inString = "";
	}while (success);
	if (numClusters > v.size()){
		cerr << "ERROR: There must be less clusters than amount of inputs" << endl;
		exit(1);
	}

//data loading
	int counter = 0;
	while (counter < v.size()){
		Coord tempCoord(length);
		for (int i = 0; i < length; ++i,++counter){
			tempCoord.push_back(v.at(counter));
		}
		Cluster<Coord>* newCluster = new Cluster<Coord>(tempCoord);
		

		//Cluster<Coord>* test1 = new Cluster<Coord>(tempCoord);
		//Cluster<Coord>* test2 = new Cluster<Coord>(tempCoord);
		//Cluster<Coord>* test3 = new Cluster<Coord>(*test1,*test2);





		clusterPoints.addPoint(newCluster);
	}
	cout << "Clusters before clustering begins: \n";
	clusterPoints.printClusters();
	

	while (clusterPoints.getNumClusters() > numClusters){
		clusterPoints.clusterPoint();
	}
	cout << "\n\n\n\nClusters after clustering has ended: \n";
	clusterPoints.printClusters();
	return 0;
}


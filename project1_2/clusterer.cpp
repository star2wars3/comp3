#include "clusterer.h"
template <typename T>
Clusterer<T>::Clusterer():globalDistance(-1), closestIndex(0),closestIndex2(0){}

template <typename T>
Clusterer<T>::~Clusterer(){
	for (int i = 0; i < points.size(); ++i){
		delete points.at(i);
	}
}

template <typename T>
void Clusterer<T>::printClusters(){
	for (int i = 0; i < points.size(); ++i){
		cout << "cluster# " << i+1 << endl;
		(*points.at(i)).printCluster();
		cout << endl;
	}
}

template <typename T>
void Clusterer<T>::addPoint(Cluster<T>* A){
	double tempDistance = 0;
	points.push_back(A);
	for (int i = 0; i < points.size()-1; ++i){
		tempDistance = (*(points.at(points.size()-1))).getDistanceTo(*points.at(i));		
		(*(points.at(points.size()-1))).updateDistanceByDistance(tempDistance, *(points.at(i)));
		(*(points.at(i))).updateDistanceByDistance(tempDistance, *(points.at(points.size()-1)));
		if ((globalDistance < 0 && tempDistance >= 0) || tempDistance < globalDistance){
			globalDistance = tempDistance;
			closestIndex = i;
			if (closestIndex2 != points.size()-1){
				closestIndex2 = points.size()-1;
			}
		}
	}
}	
template <typename T>
void Clusterer<T>::clusterPoint(){		
	Cluster<T>* A = (*(points.at(closestIndex))).generateClusterWithClosest();
	Cluster<T>* temp = points.at(closestIndex - 1);
	Cluster<T>* oldPtr = points.at(closestIndex2 - 1);
	for (int i = 0; i < points.size()-1; ++i){
		if ((*points.at(i)).getClosest() == (points.at(closestIndex2 - 1))){
			(*(points.at(i))).setClosest(points.at(closestIndex2 - 1));
		}
	}
	delete points.at(points.size()-1);
	points.pop_back();
	delete points.at(points.size()-1);
	points.pop_back();
	addPoint(A);
}

template <typename T>
int Clusterer<T>::getNumClusters(){
	return points.size();
}

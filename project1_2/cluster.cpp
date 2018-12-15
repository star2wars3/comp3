#include "cluster.h"
template <typename T>
Cluster<T>::Cluster(): distance(-1), closest(0){}

template <typename T>
Cluster<T>::Cluster(Cluster<T> A, Cluster<T> B): distance(-1), closest(0){

	data = A.getCenterWith(B);
	under.push_back(A);
	under.push_back(B);
}
template <typename T>
Cluster<T>::Cluster(T data_):data(data_){}

template <typename T>
double Cluster<T>::getDistanceTo(Cluster A){
	return data.getDistanceTo(A.getData());
}

template <typename T>
void Cluster<T>::updateDistance(Cluster A){
	double compareDistance = getDistanceTo(A);
	if(distance < 0 || compareDistance < distance){
		distance = compareDistance;
		closest = &A;
		A.updateDistanceByDistance(compareDistance, *this);
	}
}

template <typename T>
void Cluster<T>::updateDistanceByDistance(double compareDistance, Cluster A){
	if(distance < 0 || compareDistance < distance){
		distance = compareDistance;
		closest = &A;
	}
}

template <typename T>
void Cluster<T>::printCluster(){
	cout << '[';
	if (under.empty()){
		cout << data;
	}
	else{
		for (int i = 0; i < under.size(); ++i){
			printCluster();
			if (i < under.size()-1){
				cout << ",";
			}
		}
	}
	cout << ']';
}

template <typename T>
Cluster<T>* Cluster<T>::getClosest(){
	return closest;
}

template <typename T>
T Cluster<T>::getData(){
	return data;
}

template <typename T>
Cluster<T>* Cluster<T>::generateClusterWithClosest(){
	Cluster<T>* temp;
	try{	
		Cluster<T>* temp = new Cluster<T>(*getCenterWith(*closest));
		//Cluster<T>* temp = new Cluster(*this,*closest);
	}
	catch (exception e){
		cerr << "Bad_Alloc(): Not Enough Memory Available to Cluster\n";
		exit(1);
	}
	return temp;
}

template <typename T>
T* Cluster<T>::getCenterWith(Cluster A){
	return data.getCenterWith(A.getData());
}

template <typename T>
void Cluster<T>::setClosest(Cluster* closest_){
	closest = closest_;
}

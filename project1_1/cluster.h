#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Cluster{
	private:	
		T data;
		double distance;
		Cluster* closest;
		vector<Cluster> under;
	public:
		Cluster();
		Cluster(T data_);
		Cluster(Cluster A, Cluster B);
		double getDistanceTo(Cluster A);
		Cluster* getClosest();
		void setClosest(Cluster* closest_);
		void updateDistance(Cluster A);
		void updateDistanceByDistance(double compareDistance, Cluster A);
		void printCluster();
		T getData();
		Cluster* generateClusterWithClosest();
		T* getCenterWith(Cluster A);
};

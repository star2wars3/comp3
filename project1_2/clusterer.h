#include "cluster.cpp"

template <typename T>
class Clusterer{
	private:
		vector<Cluster<T>*> points;
		double globalDistance;		
		int closestIndex;
		int closestIndex2;
	public:
		Clusterer();
		~Clusterer();
		void addPoint(Cluster<T>* A);
		void printClusters();
		void clusterPoint();
		int getNumClusters();
};

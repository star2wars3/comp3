#include "clusterer.cpp"
#include <cmath>
#include <ostream>
class Coord{
	private:
		vector<double> v;
	public:
		Coord(int size = 0){}		
		int getSize(){
			return v.size();
		}
		double at(int i){
			return v.at(i);
		}
		void push_back(double d){
			v.push_back(d);
		}
		double getDistanceTo(Coord B){
			double distance = 0;
			for (int i = 0; i < v.size(); ++i){
				for (int j = 0; j < B.getSize(); ++j){				
					distance += (at(i) * B.at(j));
				}
			}
			return distance / (v.size() * B.getSize());
		}
		Coord* getCenterWith(Coord A){
			Coord* C = new Coord(getSize()* A.getSize());
			for (int i = 0; i < getSize(); ++i){
				for (int j = 0; j < A.getSize(); ++j){
					(*C).push_back((at(i) + A.at(j))/2.0);
				}
			}
			return C;
		}
		friend std::ostream& operator<< (std::ostream& out, Coord& coord) {
            for (int i = 0; i < coord.getSize(); ++i){
				out << coord.at(i);
				if (i != coord.getSize() -1){
					out << ',';
				}
				out << ' ';
			}
			return out;
        }
};

#include "clusterer.cpp"
#include <cmath>
#include <ostream>
class Coord{
	private:
		vector<double> v;
	public:
		Coord(int size = 0){
			v.reserve(size);
		}		
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
			int distance = 0;
			for (int i = 0; i < v.size(); ++i){
				distance += (at(i) * B.at(i));
			}
			return sqrt(distance);
		}
		Coord* getCenterWith(Coord A){
			Coord* C = new Coord(getSize());
			for (int i = 0; i < getSize(); ++i){
				(*C).push_back((at(i) + A.at(i))/2.0);
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

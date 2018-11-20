#include <iostream>
using namespace std;
template <typename T>
T incr(T obj){
	return ++obj;
}

class MyObject{
	private:
		int num;
	public:
		MyObject(int x = 15):num(x){
		
		}
		MyObject& operator++(){
			++num;
			return *this;
		}  
		ostream& operator<<(ostream& os){
			os << num;
			return os;
		}
		void print(){
			cout << num;
		}
};
template <typename T>
class MyObject2{
	private:
		T value;
	public:
		MyObject2(T value_):value(value_){
		
		}
		MyObject2& operator++(){
			++value;
			return *this;
		}  
		ostream& operator<<(ostream& os){
			os << value;
			return os;
		}
		void print(){
			cout << value;
		}
};


int main(){
	MyObject p;
	incr(p) << cout;
	cout << endl << endl;
	
	MyObject2<double> p2(15.5);
	incr(p2) << cout;
	cout << endl << endl;
	
	return 0;
}

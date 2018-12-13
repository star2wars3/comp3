#include <iostream>
#include <memory>
#include <ctime>
using namespace std;
unique_ptr<int[]> func1(unique_ptr<int[]> ptr, int size){
	int temp = ptr[0];
	ptr[0] = ptr[size-1];
	ptr[size-1] = temp;
	return ptr;
}

shared_ptr<int[]> func2(shared_ptr<int[]> ptr, int size){
	int temp = ptr[0];
	ptr[0] = ptr[size-1];
	ptr[size-1] = temp;
	return ptr;
}


int main(){
	int size = 10;
	int *array = new int[10];
	int *array2 = new int[10];
	srand(time(0));

	cout << endl << "Old Unique: " << endl;
	for (int i = 0; i < size; ++i){
		array[i] = rand();
		cout << array[i] <<" ";
	}
	cout << endl << "New Unique: " << endl;
	auto p = func1(unique_ptr<int[]>(array),size);
	for (int i = 0; i < size; ++i){
		cout << p[i] <<" ";
	}

	cout << endl << "Old Shared: " << endl;
	for (int i = 0; i < size; ++i){
		array2[i] = rand();
		cout << array2[i] <<" ";
	}
	cout << endl << "New Shared: " << endl;
	auto p2 = func2(shared_ptr<int[]>(array2),size);
	for (int i = 0; i < size; ++i){
		cout << p2[i] <<" ";
	}

	return 0;
}

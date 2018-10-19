#include "MyDynArray.h"
#include <climits>

MyDynArray::MyDynArray(size_t size_){
	std::cout << "Constructor called with: " << (int) size_ << std::endl;
	if (size_ > INT_MAX){
		size = 0;
	}
	else
	{
		size = size_;
		
	}
	array_ptr = new T[size];
	for (int i = 0; i < size; ++i){
		array_ptr[i] = 0;
	}
}

// get the current array size
size_t MyDynArray::getSize() const{
	std::cout << "Function getSize() called" << std::endl;
	return size;
}
T* MyDynArray::getPtr() const{
	std::cout << "Function getPtr() called" << std::endl;
	return array_ptr;
}

// put the element at the position specified by index
// if the position is out of range, increase the size of array accordingly
bool MyDynArray::set(T element, size_t index){
	std::cout << "Function set() called with element: " << element << " and index: " << index << std::endl;
	bool success = false;
	if (index >= 0){
		if (index > size){//attempt to resize if necessary
			T* new_array = new T[index + 1];//declare new storage array
			if (new_array == NULL){
				return false;
			}
			for (int i = 0; i < index + 1; i++){//copy over values
				if (i < size){
					new_array[i] = array_ptr[i];
				} 
				else{//values out of old array's range init to 0
					new_array[i] = 0;
				}
			}
			delete[] array_ptr;		//delete old array 
			array_ptr = new_array;	//replace with the new array
			size = index + 1; 		//update the size
		
		}
		//change the element at index
		array_ptr[index] = element;
		success = true;
	}
	return success;
}

// get the value at the position specified by index
T MyDynArray::get(size_t index) const{
	std::cout << "Function get() called with index " << index << std::endl;
	if (index < size && index >= 0){//if valid index
		return array_ptr[index];	//return element at index
	}
	return -1;	//else return -1 (Error value)
}

// copy constructor: should do a deep copy
MyDynArray::MyDynArray(const MyDynArray& arg){
	std::cout << "Copy constructor called" << std::endl;
	size = arg.getSize();
	array_ptr = new T[size];
	
	for (int i = 0; i < size; i++){
		array_ptr[i] = arg.getPtr()[i];
	}
}

// assignment operator: should do a deep copy
const MyDynArray& MyDynArray::operator=(const MyDynArray& rhs){
	std::cout << "Assignment operator called" << std::endl;
	if (size != rhs.getSize()){// change array size only when needed
		delete[] array_ptr;
		size = rhs.getSize();
		array_ptr = new T[size];
	}
	for (int i = 0; i < size; i++){
		array_ptr[i] = rhs.get(i);
	}
	return *this;
}

// destructor
MyDynArray::~MyDynArray(){
	std::cout << "Destructor called" << std::endl;
	delete[] array_ptr;
}

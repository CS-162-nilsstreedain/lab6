//
//  vector.hpp
//  Lab 6
//
//  Created by Nils Streedain on 11/1/21.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdlib.h>

template <class T>
class vector {
private:
	int c;
	int s;
	T *v;
public:
	vector(){
		c = 0;
		s = 0;
		v = new T(c);
	}
	
	vector(int capacity){
		c = capacity;
		s = 0;
		v = new T(c);
	}
	
	~vector(){
		delete [] v;
	}

	vector(vector<T> &other){
		s = other.size();
		c = s;
		
		T *temp;
		temp = new T[c];
		for (int i = 0; i < c; i++)
			temp[i] = other.v[i];
		
		v = temp;
	}
	
	void operator=(vector<T> &other){
		if (v != NULL)
			delete [] v;
		
		s = other.size();
		c = s;
		
		T *temp;
		temp = new T[c];
		for (int i = 0; i < c; i++)
			temp[i] = other.v[i];
		
		v = temp;
	}
	
	int size() {
		return s;
	}
	
	int cap() {
		return c;
	}

	void push_back(T ele) {
		resize(s*2);
		v[s] = ele;
		s++;
	}
	
	void resize(int newSize) {
		c = newSize;
		T *temp;
		temp = new T[c];
		for(int i = 0; i < c; i++)
			temp[i] = v[i];
		delete [] v;
		v = temp;
	}
	
	//Only performs address arithmetic
	T& operator[](int i) {
		return v[i];
	}
	
	//Check to make sure not out of bounds
	T& at(int i) {
		if (i < s)
			return v[i];

		throw ("Index not in array");
	}
};

#endif /* vector_hpp */

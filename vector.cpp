//
//  vector.cpp
//  Lab 6
//
//  Created by Nils Streedain on 11/1/21.
//

#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
	vector<int> v;   //Our vector class
	std::vector<int> stdv; //Standard vector

	//Compare operation of our vector to std
	v.push_back(23);
	v.push_back(24);
	v.push_back(25);
	stdv.push_back(23);
	
	vector<int> v2 = v;
	
	vector<int> v3;
	v3 = v;

	cout << "Our vector size: " << v.size() << endl;
	cout << "STL vector size: " << stdv.size() << endl;
	cout << "Copy Constructor vector size: " << v2.size() << endl;
	cout << "Operator Override vector size: " << v3.size() << endl;
	
	cout << "v[0]: " << v[0] << endl;
	cout << "v.at(0): " << v.at(0) << endl;
	
	v.resize(2);
	cout << "Our vector cap: " << v.cap() << endl;
	

	return 0;
}

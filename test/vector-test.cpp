/*
Programmer 	: EOF
Date			: 2015.03.31
file				: 4vector-test.cpp

Code description:
	This is a demo to show how the vector works.
*/

#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	size_t i = 0;
	vector<int> iv;
	cout << "size" << iv.size() << endl;				// size = 2
	cout << "capacity = " << iv.capacity() << endl; 	// capacity = 2

	iv.push_back(1);
	cout << "size" << iv.size() << endl;				// size = 3
	cout << "capacity = " << iv.capacity() << endl; 	// capacity = 4

	iv.push_back(2);
	cout << "size" << iv.size() << endl;				// size = 4
	cout << "capacity = " << iv.capacity() << endl; 	// capacity = 4

	iv.push_back(3);
	cout << "size" << iv.size() << endl;				// size = 5
	cout << "capacity = " << iv.capacity() << endl; 	// capacity = 8

	iv.push_back(4);
	cout << "size" << iv.size() << endl;				// size = 6
	cout << "capacity = " << iv.capacity() << endl; 	// capacity = 8


	for (i = 0; i < iv.size(); i++)
	{
		cout << iv.at(i) << ' ';
	}
	cout << endl;

	iv.push_back(5);
	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	
	for (i = 0; i < iv.size(); i++)
	{
		cout << iv.at(i) << ' ';
	}
	cout << endl;

	iv.pop_back();
	iv.pop_back();
	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	

	iv.pop_back();
	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	

	vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);

	if (ivite != iv.end())
	{
		iv.erase(ivite);
	}

	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	
	for (i = 0; i < iv.size(); i++)
	{
		cout << iv.at(i) << ' ';
	}
	cout << endl;

	ivite = find(iv.begin(), iv.end(), 2);

	if( ivite != iv.end())
	{
		iv.insert(ivite, 3, 7);
	}

	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	
	for (i = 0; i < iv.size(); i++)
	{
		cout << iv.at(i) << ' ';
	}
	cout << endl;

	iv.clear();
	cout << "size" << iv.size() << endl;				// size = 
	cout << "capacity = " << iv.capacity() << endl; 	// capacity =	
	return 0;
}

#include "../vector"
#include <iostream>
#include "../algorithm"

using namespace sgistd;
using namespace std;

int main()
{
	size_t i = 0;
	int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
	vector<int> ivec(ia, ia+9);

	make_heap(ivec.begin(), ivec.end());
	for (i = 0; i < ivec.size(); ++i) {
		cout << ivec[i] << ' '; //9 5 8 3 4 0 2 3 1
	}
	cout << endl;
	ivec.push_back(7);
	push_heap(ivec.begin(), ivec.end());
	for (i = 0; i < ivec.size(); ++i) {
		cout << ivec[i] << ' '; //9 7 8 3 5 0 2 3 1 4 
	}
	cout << endl;

	pop_heap(ivec.begin(), ivec.end());
	cout << ivec.back() << endl; //9 return but not remove
	ivec.pop_back();			 //remove last elem and no return

	for (i = 0; i < ivec.size(); ++i) {
		cout << ivec[i] << ' ';  //8 7 4 3 5 0 2 3 1
	}
	cout << endl;

	sort_heap(ivec.begin(), ivec.end());
	for (i = 0; i < ivec.size(); ++i) {
		cout << ivec[i] << ' ';  //0 1 2 3 4 5 7 8
	}
	cout << endl;
}


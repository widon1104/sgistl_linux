#include "../set"
#include <iostream>
#include "../algorithm"

using namespace sgistd;
using namespace std;

int main()
{
	int ia[5] = {0, 1, 2, 3, 4};
	set<int> iset(ia, ia+5);

	cout << "size=" << iset.size() << endl; //size=5
	cout << "3 count=" << iset.count(3) << endl; //3 count=1
	iset.insert(3);
	cout << "size=" << iset.size() << endl; //size=5
	cout << "3 count=" << iset.count(3) << endl; //3 count=1
	iset.insert(5);
	cout << "size=" << iset.size() << endl; //size=6
	cout << "3 count=" << iset.count(3) << endl; //3 count=1
	iset.erase(1);
	cout << "size=" << iset.size() << endl; //size=5
	cout << "3 count=" << iset.count(3) << endl; //3 count=1
	cout << "1 count=" << iset.count(1) << endl; //1 count=0
	for (auto it = iset.begin(); it != iset.end(); ++it) {
		cout << *it << ' ';					//0 2 3 4 5
	}
	cout << endl;
	auto it = find(iset.begin(), iset.end(), 3);
	if (it != iset.end()) {
		cout << "3 found" << endl;			//3 found
	}
	it = find(iset.begin(), iset.end(), 1);
	if (it == iset.end()) {
		cout << "1 not found" << endl;		//1 not found
	}
	it = iset.find(3);
	if (it != iset.end()) {
		cout << "3 found" << endl;			//3 found
	}
	it = iset.find(1);
	if (it == iset.end()) {
		cout << "1 not found" << endl;		//1 not found
	}
	//*it = 9; //error
	return 0;
}

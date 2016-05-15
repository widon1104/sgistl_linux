#include "../tree.h"
#include <iostream>

using namespace sgistd;
using namespace std;

int main()
{
	rb_tree<int, int, identity<int>, sgistd::greater<int>> itree;
	cout << itree.size() << endl;	// 0
	itree.insert_unique(10);
	itree.insert_unique(7);
	itree.insert_unique(8);
	itree.insert_unique(15);
	itree.insert_unique(5);
	itree.insert_unique(6);
	itree.insert_unique(11);
	itree.insert_unique(13);
	itree.insert_unique(12);
	cout << itree.size() << endl;	// 9
	for (auto it = itree.begin(); it != itree.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}


#include "../deque"
#include <iostream>
#include "../algorithm"

using namespace sgistd;
using namespace std;

int main()
{
	size_t i = 0;
	//20个元素，初值都为9
	deque<int, alloc> ideq(20, 9);
	cout << "size=" << ideq.size() << endl;	//size=20

	for (i = 0; i < ideq.size(); ++i) {
		ideq[i] = i;
	}
	for (i = 0; i < ideq.size(); ++i) {
		cout << ideq[i] << ' ';		//0 1 2 3 4 5 6...19
	}
	cout << endl;
	for (i = 0; i < 3; ++i) {
		ideq.push_back(i);
	}
	for (i = 0; i < ideq.size(); ++i) {
		cout << ideq[i] << ' ';		//0 1 2 3...19 0 1 2
	}
	cout << endl;
	cout << "size=" << ideq.size() << endl; //size=23

	ideq.push_back(3);
	for (i = 0; i < ideq.size(); ++i) {
		cout << ideq[i] << ' ';			//0 1 2 3...19 0 1 2 3
	}
	cout << endl;
	cout << "size=" << ideq.size() << endl; //size=24

	//在前端添加1个元素，99
	ideq.push_front(99);
	for (i = 0; i < ideq.size(); ++i) {
		cout << ideq[i] << ' ';			//99 0 1 2 3...19 0 1 2 3
	}
	cout << endl;
	cout << "size=" << ideq.size() << endl; //size=25

	ideq.push_front(98);
	ideq.push_front(97);
	for (i = 0; i < ideq.size(); ++i) {
		cout << ideq[i] << ' ';		//97 98 99 0 1 2 3...19 0 1 2 3
	}
	cout << endl;
	//size=27
	cout << "size=" << ideq.size() << endl;		//size=27

	deque<int, alloc>::iterator itr;
	itr = find(ideq.begin(), ideq.end(), 99);
	//99
	cout << *itr << endl;
	//99
	cout << *(itr._M_cur) << endl;
	return 0;
}


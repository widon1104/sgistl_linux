#include "../algorithm"
#include "../vector"
#include "../functional"
#include <iostream>
#include "../iterator"
#include "../string"

using namespace sgistd;

template <typename T>
struct display {
	void operator()(const T& x) const
	{
		std::cout << x << ' ';
	}
};

int main()
{
	int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> iv1(ia, ia+5);
	vector<int> iv2(ia, ia+9);

	auto it = mismatch(iv1.begin(), iv1.end(), iv2.begin());
	if (it.first != iv1.end()) {
		std::cout << *(it.first) << std::endl;
	}
	if (it.second != iv2.end()) {
		std::cout << *(it.second) << std::endl;
	}

	std::cout << equal(iv1.begin(), iv1.end(), iv2.begin()) << std::endl;
	std::cout << equal(iv1.begin(), iv1.end(), &ia[3]) << std::endl;
	std::cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>()) <<
	   	std::endl;
	fill(iv1.begin(), iv1.end(), 9);
	for_each(iv1.begin(), iv1.end(), display<int>()); //9 9 9 9 9
	std::cout << std::endl;

	fill_n(iv1.begin(), 3, 7);
	for_each(iv1.begin(), iv1.end(), display<int>()); //7 7 7 9 9
	std::cout << std::endl;
	auto it1 = iv1.begin();
	auto it2 = it1;
	advance(it2, 3);
	iter_swap(it1, it2);	//迭代器所指元素对调
	std::cout << *it1 << ' ' << *it2 << std::endl;
	for_each(iv1.begin(), iv1.end(), display<int>()); //9 7 7 7 9
	std::cout << std::endl;

	std::cout << std::max(*it1, *it2) << std::endl;		//9
	std::cout << std::min(*it1, *it2) << std::endl;		//7

	string stra1[] = {"Jamie", "JJHou", "Jason"};
	string stra2[] = {"Jamie", "JJhou", "Jerry"};

	std::cout << lexicographical_compare(stra1, stra1+2, stra2, stra2+2) 
		<< std::endl;
	std::cout << lexicographical_compare(stra1, stra1+2, stra2, stra2+2, 
			greater<string>()) << std::endl;
	return 0;
}

#include "../set"
#include <iostream>
#include "../algorithm"
#include "../iterator"

using namespace sgistd;

template <typename T>
struct display {
	void operator()(const T& x)
	{
		std::cout << x << ' ';
	}
};

int main()
{
	int ia1[6] = {1, 3, 5, 7, 9, 11};
	int ia2[7] = {1, 1, 2, 3, 5, 8, 13};

	multiset<int> s1(ia1, ia1+6);
	multiset<int> s2(ia2, ia2+7);

	for_each(s1.begin(), s1.end(), display<int>());
	std::cout << std::endl;
	for_each(s2.begin(), s2.end(), display<int>());
	std::cout << std::endl;

	auto first1 = s1.begin();
	auto last1 = s1.end();
	auto first2 = s2.begin();
	auto last2 = s2.end();

	std::cout << "Union of s1 and s2: ";
	set_union(first1, last1, first2, last2,
			ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	first1 = s1.begin();
	first2 = s2.begin();
	std::cout << "Intersection of s1 and s2: ";
	set_intersection(first1, last1, first2, last2,
			ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	first1 = s1.begin();
	first2 = s2.begin();
	std::cout << "Difference of s1 and s2: (s1-s2)";
	set_difference(first1, last1, first2, last2,
			ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	first1 = s1.begin();
	first2 = s2.begin();
	std::cout << "Symmetric difference of s1 and s2: ";
	set_symmetric_difference(first1, last1, first2, last2,
			ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	first1 = s2.begin();
	last1 = s2.end();
	first2 = s1.begin();
	last2 = s1.end();
	std::cout << "Difference of s1 and s2: (s2-s1)";
	set_difference(first1, last1, first2, last2,
			ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}

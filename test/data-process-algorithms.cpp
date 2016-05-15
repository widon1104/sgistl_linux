#include "../algorithm"
#include "../vector"
#include "../functional"
#include <iostream>

using namespace sgistd;

template <typename T>
struct display {
	void operator()(const T& x) const
	{
		std::cout << x << ' ';
	}
};

struct even {
	bool operator()(int x) const
	{
		return x%2 ? false : true;
	}
};

class even_by_two {
public:
	int operator()() const
	{
		return _x += 2;
	}
private:
	static int _x;
};

int even_by_two::_x = 0;

int main()
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
	vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));

	//找出iv之中相邻元素值相等的第一个元素
	std::cout << *adjacent_find(iv.begin(), iv.end()) << std::endl;

	//找出iv之中相邻元素值相等的第一个元素
	std::cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) <<
	   	std::endl;

	//值为6的元素个数
	std::cout << count(iv.begin(), iv.end(), 6) << std::endl;

	//bind1st(const Operation& op, const T& x)就是这么一个操作：x op value
	//bind2nd(const Operation& op, const T& x)就是这么一个操作：value op x
	//小于7的元素个数
	std::cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)) <<
	   	std::endl;

	//元素值为4的第一个元素所在位置
	std::cout << *find(iv.begin(), iv.end(), 4) << std::endl;

	//iv之中大于2的第一个元素所在位置的值
	std::cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2))<<
		std::endl;

	vector<int> iv2(ia+6, ia+8);
	std::cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << std::endl;
	std::cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << std::endl;
	for_each(iv.begin(), iv.end(), display<int>());
	std::cout << std::endl;

	generate(iv2.begin(), iv2.end(), even_by_two());
	for_each(iv2.begin(), iv2.end(), display<int>());
	std::cout << std::endl;
	
	generate_n(iv.begin(), 3, even_by_two());
	for_each(iv.begin(), iv.end(), display<int>());
	std::cout << std::endl;
	//删除元素6
	remove(iv.begin(), iv.end(), 6);
	for_each(iv.begin(), iv.end(), display<int>());
}

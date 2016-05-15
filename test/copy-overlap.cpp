#include <iostream>
#include "../algorithm"
#include "../deque"

using namespace sgistd;

template <class T>
struct display {
	void operator()(const T&x)
	{
		std::cout << x << ' ';
	}
};

int main()
{
	{
		int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		//输出区间的终点和输入区间重叠，正常工作
		copy(ia+2, ia+7, ia);
		for_each(ia, ia+9, display<int>()); //2 3 4 5 6 5 6 7 8
		std::cout << std::endl;
	}
	{
		int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		//输出区间的终点和输入区间重叠，可能会有问题
		//本例结果正确, copy算法使用了memmove()
		copy(ia+2, ia+7, ia+4);
		for_each(ia, ia+9, display<int>()); //0 1 2 3 2 3 4 5 6
		std::cout << std::endl;
	}
	{
		int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		deque<int> id(ia, ia+9);

		deque<int>::iterator first = id.begin();
		deque<int>::iterator last = id.end();
		advance(first, 2);
		std::cout << *first << std::endl;
		advance(last, -2);
		std::cout << *last << std::endl;

		deque<int>::iterator result = id.begin();
		std::cout << *result << std::endl;
		//输出区间的终点和输入区间重叠，正常工作
		copy(first, last, result);
		for_each(id.begin(), id.end(), display<int>());//2 3 4 5 6 5 6 7 8
		std::cout << std::endl;
	}
	{
		int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		deque<int> id(ia, ia+9);

		deque<int>::iterator first = id.begin();
		deque<int>::iterator last = id.end();
		advance(first, 2);
		std::cout << *first << std::endl;
		advance(last, -2);
		std::cout << *last << std::endl;

		deque<int>::iterator result = id.begin();
		advance(result, 4);
		std::cout << *result << std::endl;
		copy(first, last, result);
		//本例结果错误，因为调用的copy算法不再使用
		//memmove()执行实际的复制操作
		for_each(id.begin(), id.end(), display<int>()); //0 1 2 3 2 3 2 3 2
		std::cout << std::endl;
	}
	return 0;
}

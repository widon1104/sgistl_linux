#include "../numeric"
#include "../vector"
#include "../functional"
#include <iostream>
#include "../iterator"

using namespace sgistd;

int main()
{
	int ia[5] = {1, 2, 3, 4, 5};
	vector<int> iv(ia, ia+5);

	std::cout << accumulate(iv.begin(), iv.end(), 0) << std::endl;
	//15 0 + 1+2+3+4+5
	std::cout << accumulate(iv.begin(), iv.end(), 0, minus<int>()) << std::endl;
	//-15 0 + (-1-2-3-4-5)
	std::cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) <<
		std::endl;
	//65 10 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5
	std::cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10,
			minus<int>(), plus<int>()) << std::endl;

	ostream_iterator<int> oite(std::cout, " ");
	//-20 10 - (1+1) - (2+2) - ... - (5+5)
	partial_sum(iv.begin(), iv.end(), oite);
	std::cout << std::endl;
	//1 3 6 10 15
	//
	partial_sum(iv.begin(), iv.end(), oite, minus<int>());
	//1 -1 -4 -8 -13
	std::cout << std::endl;

	adjacent_difference(iv.begin(), iv.end(), oite);
	//1 1 1 1 1
	std::cout << std::endl;

	adjacent_difference(iv.begin(), iv.end(), oite, plus<int>());
	//1 3 5 7 9			op(n, n-1)
	std::cout << std::endl;
	
	std::cout << power(10, 3) << std::endl; //10*10*10
	std::cout << power(10, 3, plus<int>()) << std::endl; //10+10+10

	int n = 3;
	iota(iv.begin(), iv.end(), n); //n, n+1, n+2...
	for (size_t i = 0; i < iv.size(); ++i) {
		std::cout << iv[i] << ' ';
	}
	return 0;
}


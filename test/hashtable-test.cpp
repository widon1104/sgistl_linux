#include "../hash_set"
#include <iostream>
using namespace sgistd;

int main()
{
	hashtable<int, int, hash<int>, identity<int>,
		equal_to<int>> iht(50, hash<int>(), equal_to<int>()); //指定保留50个buckets
	std::cout << iht.size() << std::endl;		//0
	std::cout << iht.bucket_count() << std::endl;	//53
	std::cout << iht.max_bucket_count() << std::endl;	//53

	iht.insert_unique(59);
	iht.insert_unique(63);
	iht.insert_unique(108);
	iht.insert_unique(2);
	iht.insert_unique(53);
	iht.insert_unique(55);
	std::cout << iht.size() << std::endl;
	for (auto it = iht.begin(); it != iht.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	for (size_t i = 0; i < iht.bucket_count(); ++i) {
		int n = iht.elems_in_bucket(i);
		if (n != 0) {
			std::cout << "bucket[" << i << "] has " << n << " elems." <<
			   	std::endl;
		}
	}
	for (size_t i = 0; i <= 47; i++) {
		iht.insert_equal(i);
	}
	std::cout << iht.size() << std::endl; //54
	//hashtable<T>::resize re-hashing
	std::cout << iht.bucket_count() << std::endl;	//97
	for (size_t i = 0; i < iht.bucket_count(); ++i) {
		int n = iht.elems_in_bucket(i);
		if (n != 0) {
			std::cout << "bucket[" << i << "] has " << n << " elems." <<
			   	std::endl;
		}
	}
	for (auto it = iht.begin(); it != iht.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << *(iht.find(2)) << std::endl;
	std::cout << iht.count(2) << std::endl;
	return 0;
}


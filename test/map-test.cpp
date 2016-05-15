#include "../map"
#include <iostream>
#include "../string"

using namespace sgistd;
using namespace std;

int main()
{
	map<std::string, int> simap;			//std::string is key, int is value
	simap[std::string("jjhou")] = 1;
	simap[std::string("jerry")] = 2;
	simap[std::string("jason")] = 3;
	simap[std::string("jimmy")] = 4;

	//std::pair<std::string, int> value(std::string("david"), 5);
	//simap.insert(value);

	for (auto it = simap.begin(); it != simap.end(); ++it) {
		cout << it->first << ' ' <<
			it->second << endl;
	}
	int num = simap[std::string("jjhou")];
	cout << num << endl;

	auto it = simap.find(std::string("mchen"));
	if (it == simap.end()) {
		cout << "mchen not found" << endl;
	}

	it = simap.find(std::string("jerry"));
	if (it != simap.end()) {
		cout << "jerry found" << endl;
		it->second = 9;
	}
	num = simap[std::string("jerry")];
	cout << num << endl;
	return 0;
}

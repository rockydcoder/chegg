#include <iostream>
#include <vector>
using namespace std;

bool binary_search() {

}
bool insertAndFind(int value) {
	vector<int> numbers(101);
	for (int i = -50; i < 50; i++)
		numbers.push_back(i);
	numbers.insert(numbers.begin(), value);
	return binary_search(numbers.begin(), numbers.end(), value);
}




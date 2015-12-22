#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	vector<int> countDown; // Declare vector countDown
	cout << "Enter new size of vector" << endl;
	int newSize, i;
	cin >> newSize; // Take new size of vector as input
	for (i = newSize; i > 0; i--) {
		countDown.push_back(i); // Populate the vector with elements
	}
	for (i = 0; i < countDown.size(); i++) {
		cout << countDown[i] << " "; // Output each element of vector
	}
	cout << endl;
}
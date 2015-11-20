#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string start, last;
	while (true) {
		cout << "Enter first four-letter word" << endl;
		cin >> start;
		if (start.length() == 4)
			break;
		else
			cout << "Not a four-letter word. Enter again" << endl;
	}
	while (true) {
		cout << "Enter second four-letter word" << endl;
		cin >> last;
		if (last.length() == 4)
			break;
		else
			cout << "Not a four-letter word. Enter again" << endl;
	}
	transform(start.begin(), start.end(), start.begin(), ::toupper);
	transform(last.begin(), last.end(), last.begin(), ::toupper);
	int counter = 0;
	cout << start << "-";
	for (int i = 0; i < 4; i++) {

		if (start.at(i) == last.at(i))
			continue;
		else {
			start[i] = last[i];
			cout << start;
			if (start.compare(last) != 0)
				cout << "-";
			counter++;
		}
	}
	cout << endl << "Number of steps = " << counter << endl;
}
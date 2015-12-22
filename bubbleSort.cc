#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
char *get_input_file_name() {
	char* inputFileName = new char[100];
	cout << "Please enter input file name\n";
	cin >> inputFileName;
	return (inputFileName);
}

char *get_output_file_name() {
	char* outputFileName = new char[100];
	cout << "Please enter output file name\n";
	cin >> outputFileName;
	return outputFileName;
}

int bubble_sort_method(vector<int> *v) {
	bool flag;
	int numberOfSwaps;
	for (int i = 0; i < v->size(); i++) {
		flag = false;
		for (int j = 0; j < v->size()-1; j++) {
			if ((*v)[j] > (*v)[j+1]) {
				flag = true;
				numberOfSwaps++;
				int temp = (*v)[j];
				(*v)[j] = (*v)[j+1];
				(*v)[j+1] = temp;
			}
		}
		if (!flag)
			break;
	}
	return numberOfSwaps;
}

void display_sorted_array(vector<int> *v) {
	for(vector<int>::iterator it = v->begin(); it != v->end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	char *inputFileName = get_input_file_name();
	vector<int> v;
	ifstream file(inputFileName);
	string line;
	while (getline(file, line)) {
		stringstream lineStream(line);
		int value;
		while (lineStream >> value) {
			v.push_back(value);
		}
	}
	file.close();
	int numberOfSwaps = bubble_sort_method(&v);
	char *outputFileName = get_output_file_name();
	ofstream output(outputFileName);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		output << *it << endl;
	}
	output << numberOfSwaps;
	output.close();
	display_sorted_array(&v);

}
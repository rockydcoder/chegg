#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	vector<string> lines;
	string line;
	int *assignment, *totalMarks, *percent, *totalAssignment;
	ifstream file ("studentReport.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
		}
	}

	for (int i = 0; i < lines.size(); i++) {
		istringstream iss(lines[i]);
		vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};

	}
}
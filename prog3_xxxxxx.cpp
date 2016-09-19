#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;

int str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  { 
      //ERROR 
  }
  return num;
}


int main() {
	ios::sync_with_stdio(false);
	vector<string> lines;
	string line;
	ifstream file("test.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
		}
	}

	else {
		cout << "Could not open file" << endl;
	}

	for (int i = 0; i < lines.size(); i++) {
		vector<string> tokens;
		int correctAnswers = 0, timeTaken = 0, totalScore = 0;
		istringstream iss(lines[i]);
		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(tokens));
		correctAnswers = str2int(tokens[1]);
		timeTaken = str2int(tokens[2]);
		if (timeTaken < 30)
			totalScore = 5;
		totalScore += correctAnswers*10;
		cout << tokens[0] << " has a ratIQ of " << totalScore << endl;
	}
}
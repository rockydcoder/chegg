#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
int main() {
	ios::sync_with_stdio(false);
	vector<string> tokens;
	string line;
	ifstream file ("2.5_day.csv");
	if (file.is_open()) {
		getline(file, line);
	}
	else {
		cout << "Could not open file" << endl;
	}

	tokens = split(line, ',');
	for (int i = 0; i < tokens.size(); i++)
		cout << i << " " << tokens[i] << endl;
}
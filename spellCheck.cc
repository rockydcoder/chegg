#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;
int main() {
	unordered_set<string> dict;
	string line;
	ifstream file ("dict.dat");
	if (file.is_open()) {
		while (getline(file, line)) {
			dict.insert(line);
		}
	}

	string input;
	cout << "Enter name of input file" << endl;
	cin >> input;
	ifstream inputFile (input);
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			stringstream ss(line);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			string word;
			while (begin != end) {
				word  = *begin++;
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if (word.back() == '.' || word.back() == ',' || word.back() == '?' || word.back() == '!') {
					word = word.erase(word.length()-1);

				}		
				 unordered_set<string>::const_iterator got = dict.find (word);

				  if ( got == dict.end() )
				    std::cout << word << endl;

			}

		}
	}

}
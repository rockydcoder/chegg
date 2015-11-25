#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }
int main() {
	ios::sync_with_stdio(false);
	vector<string> lines;
	string line;
	ifstream file ("music.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
		}
	}
	else {
		cout << "Could not open file" << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		// a. Remove the lead numbers, any periods, and any spaces so that the first word of the title is the first word of the line.
		lines[i] = lines[i].substr(3, string::npos);
		// c. Replace all dash - characters on any line before the end of the line by a space except the last one.
		bool flag = false;
		int dashPosition = 0;
		for (int j = lines[i].size()-1; j >= 0; j--) {
			if (lines[i].at(j) == '-' && !flag) {
				flag = true;
				dashPosition = j;
			}
			else if (lines[i].at(j) == '-' && flag) {
				lines[i][j] = ' ';
			}
		}
		// b. Replace any multiple spaces with a single space.
		string::iterator new_end = std::unique(lines[i].begin(), lines[i].end(), BothAreSpaces);
		lines[i].erase(new_end, lines[i].end());
		// Recalculate dash position
		for (int j = 0; j < lines[i].size(); j++) {
			if (lines[i].at(j) == '-') {
				dashPosition = j;
				break;
			}
		}
		// e. Write code to move such initial words to just before the - character.
		int lastBlankSpacePosition = -1;
		string word;
		for (int j = 0; j < dashPosition; j++) {
			if (lines[i].at(j) == ' ') {
				word = lines[i].substr(lastBlankSpacePosition+1, j - lastBlankSpacePosition - 1);
				if (word == "A") {
					lines[i] = lines[i].replace(lastBlankSpacePosition+1, 2, "");
					dashPosition -= 2;
				}
				else if (word == "An") {
					lines[i] = lines[i].replace(lastBlankSpacePosition+1, 3, "");
					dashPosition -= 3;
				}
				else if (word == "The") {
					lines[i] = lines[i].replace(lastBlankSpacePosition+1, 4, "");
					dashPosition -= 4;
				}
				lastBlankSpacePosition = j;

			}
		}
		// f. Move the composer’s names to the beginning of the line, followed by the character, followed by the composition title.
		lines[i] = lines[i].substr(dashPosition+2, string::npos) + " - " + lines[i].substr(0, dashPosition-1);
		new_end = std::unique(lines[i].begin(), lines[i].end(), BothAreSpaces);
		lines[i].erase(new_end, lines[i].end());
	}
	sort(lines.begin(), lines.end());
	for (int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}
}
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class ArrayListClass {

public:
	ArrayListClass();
	void printAll();
	void searchName(string name);

private:
	list<string> myarray[27];
};

ArrayListClass::ArrayListClass() {
	string line;
	ifstream file ("names.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			char start = line[0];
			int index = start - 64;
			myarray[index].push_back(line);
		}
	}
	else {
		cout << "Could not open file" << endl;
	}
}

void ArrayListClass::printAll() {
	for (int i = 1; i < 27; i++) {
		cout << "Printing words that start with " << char(i-1 + 'A') << '\n';
	    list<string>::iterator iter = myarray[i].begin();
	    while (iter != myarray[i].end())
	    {
	      cout << '\t' << *iter << '\n';
	      iter++;
	    }
	}
}

void ArrayListClass::searchName(string name) {
	int index = name[0] - 64;
	list<string>::iterator iter = find(myarray[index].begin(), myarray[index].end(), name);
	if (iter != myarray[index].end())
		cout << "Name " << name << " is present\n";
	else
		cout << "Name "<< name << " is absent\n";
}

int main() {
	ArrayListClass myClass;
	myClass.printAll();
	myClass.searchName("ZUK");
	myClass.searchName("RAKA");
}
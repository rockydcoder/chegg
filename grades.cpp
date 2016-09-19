#include <iostream>
#include <string.h>
#include <fstream>
using namespace std; 
void printFileToScreen(); 
int main() { 
//close the input file here 
	printFileToScreen(); 
	return 0; 
} 

void printFileToScreen() { 
	ifstream inData; 
	string line = ""; 
	inData.open("class_statistics.txt"); 
	while(inData) { 
		getline(inData,line); 
		cout << line << endl; 
	} 
	inData.close(); }
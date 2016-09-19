#include <iostream>
using namespace std;
int getInt(char c) {
	switch (c) {
		case 'A': return 0;
		case 'B': return 1;
		case 'C': return 2;
		case 'D': return 3;
		case 'L': return 4;
		case 'M': return 5;
		case 'N': return 6;
		case 'S': return 7;
	}
}

int main() {
	int matrix[8][8] = 
	{
		{0, 0, 606, 0, 0, 0, 0, 0},
		{0, 0, 860, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 908, 0, 0, 0, 0, 0},
		{0, 0, 0, 834, 0, 0, 0, 349},
		{595, 0, 0, 0, 0, 0, 1090, 0},
		{760, 191, 722, 0, 2451, 0, 0, 2534},
		{0, 0, 1855, 957, 349, 0, 0, 0}
	};
	int choice, numOfEdges = 15;
	char a, b;
	int distance;
	
	do {
		cout << "1 - Insert" << endl
	<< "2 - Delete" << endl
	<< "3 - Show total number of edges" << endl
	<< "4 - Show the matrix" << endl
	<< "5 - Exit" << endl;

	
	cin >> choice;
		switch (choice) {
		case 1:
		{cout << "Enter origin city\n";
				cin >> a;
				cout << "Enter destination city\n";
				cin >> b;
				if (matrix[getInt(a)][getInt(b)] != 0)
					cout << "Edge already exits!";
				else {
					cout << "Enter distance\n";
					cin >> distance;
					matrix[getInt(a)][getInt(b)] = distance;
					numOfEdges++;
				}
				break;}

		case 2:
		{cout << "Enter origin city\n";
				cin >> a;
				cout << "Enter destination city\n";
				cin >> b;
				if (matrix[getInt(a)][getInt(b)] == 0)
					cout << "No edge available!";
				else {
					matrix[getInt(a)][getInt(b)] = 0;
					numOfEdges--;
				}
				break;}

		case 3:
		{cout << "Number of edges = " << numOfEdges << endl;
				break;}

		case 4:
		{for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << matrix[i][j] << "\t";
					}
					cout << endl;
				}
				break;}
	}
} while ( choice != 5);
}
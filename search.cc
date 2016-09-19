#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

void bubble_sort_method(vector<int> *v) {
	bool flag;
	for (int i = 0; i < v->size(); i++) {
		flag = false;
		for (int j = 0; j < v->size()-1; j++) {
			if ((*v)[j] > (*v)[j+1]) {
				flag = true;
				int temp = (*v)[j];
				(*v)[j] = (*v)[j+1];
				(*v)[j+1] = temp;
			}
		}
		if (!flag)
			break;
	}
}

int sequentialSearch(int item, vector<int> *v, int left, int right) {
	int temp = (*v)[left], numOfComp = 0;
	while (left <= right && item <= temp) {
		numOfComp++;
		if (item == temp) {
			cout << "Position of number = " << left+1 << endl; 
			return numOfComp;
		}
		else {
			left++;
		}
	}
}

int binarySearch(int item, vector<int> *v) {
	int numOfComp = 0;
	bool flag = false;
	int left = 0, right = 999, mid;
	while (right - left > 15) {
		numOfComp++;
		mid = (left+right)/2;
		if (item < (*v)[mid]) {
			right = mid;
		}
		else if (item > (*v)[mid]) {
			left = mid;
		}
		else {
			flag = true;
			cout << "Position of number = " << mid+1 << endl;
			break;
		}
	}
	cout << "Number of comparisions in binary search = " << numOfComp << endl;
	if (!flag) {
		int seqSearch = sequentialSearch(item, v, left, right);
		cout << "Number of comparisions in sequential search = " << seqSearch << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	vector<int> v;
	int temp;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		temp = rand() % 1000 + 1;
		v.push_back(temp);
	}
	bubble_sort_method(&v);
	binarySearch(4, &v);	

}
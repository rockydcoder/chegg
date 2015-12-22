#include <iostream>
using namespace std;
class UsingArrays {
private:
	int* arr;
	int size;
	int maxCapacity;

public:
	UsingArrays();
	void addElement(int element);
	int getSize();
	void toTop(int element);
	void printArray();
};

UsingArrays::UsingArrays(void) {
	arr = new int[5];
	size = 0;
	maxCapacity = 5;
}

void UsingArrays::printArray() {
	for (int i = 0; i < getSize(); i++) {
		cout << arr[i] << endl;
	}
}

int UsingArrays::getSize() {
	return size;
}

void UsingArrays::addElement(int element) {
	if (getSize() >= maxCapacity) {
		maxCapacity *= 2;
		int* newArr = new int[maxCapacity];
		copy(arr, arr + getSize(), newArr);
		delete[] arr;
		arr = newArr;
	}
	arr[size] = element;
	size++;
}

void UsingArrays::toTop(int element) {
	if (getSize() != 0) {
		if (getSize() >= maxCapacity) {
			maxCapacity *= 2;
			int* newArr = new int[maxCapacity];
			copy(arr, arr + getSize(), newArr);
			delete[] arr;
			arr = newArr;
		}
		for (int i = 0; i < size; i++) {
			int temp = arr[i];
			arr[i] = element;
			element = temp;
		}
		arr[size++] = element;
	}
}

int main() {
	UsingArrays testObject;
	testObject.addElement(1);
	testObject.addElement(2);
	testObject.addElement(3);
	testObject.addElement(4);
	testObject.addElement(5);
	testObject.addElement(6);
	testObject.printArray();
	testObject.toTop(0);
	testObject.printArray();
}

#include <iostream>
using namespace std;
int findNumWays(int numberOfSteps);
int main() {
	ios::sync_with_stdio(false);
	// call function here

}
int findNumWays(int numberOfSteps) {
	if (numberOfSteps < 3 && numberOfSteps > 0) {
		return numberOfSteps;
	}
	if (numberOfSteps == 0) {
		return 1;
	}
	return findNumWays(numberOfSteps-1) + findNumWays(numberOfSteps-2) + findNumWays(numberOfSteps-3);
}
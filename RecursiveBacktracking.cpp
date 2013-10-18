#include <iostream>
#include "vector.h"
using namespace std;


bool isMeasurable(int target, Vector<int>& weights) {
	int right = 0;
	for (int i = 0; i< weights.size(); i++)
		right += weights[i];
	if (target == right) return true; // base case
	if (right == 0) return false;

	int len = weights.size();
	while (len > 0) {
		int pick = weights[0];
		weights.remove(0);
		if (isMeasurable(target, weights) || isMeasurable(target + pick, weights)) return true;
		weights.add(pick);
		len--;
	}
	return false;
}

int main() {
	Vector<int> weights;
	weights += 1, 2, 5;
	cout << isMeasurable(9, weights) << endl;
	return 0;
};
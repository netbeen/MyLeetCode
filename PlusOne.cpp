/*
 * PlusOne.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 用vector模拟加1的加法，没啥技术含量，注意进位即可。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int addOneBit(int add) {
		short carry = (carryBit == true) ? 1 : 0;
		carryBit = false;
		if (add + carry  <= 9) {
			return add + carry;
		} else {
			carryBit = true;
			return 0;
		}
	}

	vector<int> plusOne(vector<int> &digits) {
		carryBit = true;
		for (size_t i = 0; i < digits.size(); i++) {
			digits.at(digits.size() - i - 1) = addOneBit(digits.at(digits.size() - i - 1));
		}
		if (carryBit == true) {
			digits.insert(digits.begin(), 1, 1);
		}
		while (digits.at(0) == 0 ) {
			digits.erase(digits.begin());
		}

		return digits;
	}
private:
	bool carryBit;
};

void printVector(vector<int> digits) {
	for (size_t i = 0; i < digits.size(); i++) {
		cout << digits.at(i);
	}
	cout << endl;
}

int main() {
	Solution s;

	int array1[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> digits1(array1, array1 + 7);
	printVector(s.plusOne(digits1));

	int array2[] = { 0, 0, 0 };
	vector<int> digits2(array2, array2 + 3);
	printVector(s.plusOne(digits2));

	int array3[] = { 9, 9, 9 };
	vector<int> digits3(array3, array3 + 3);
	printVector(s.plusOne(digits3));

	int array4[] = { 8, 9, 9 };
	vector<int> digits4(array4, array4 + 3);
	printVector(s.plusOne(digits4));
	return 0;
}

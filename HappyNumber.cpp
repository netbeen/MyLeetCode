/*
 * HappyNumber.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: netbeen
 */

/*
 * 找出happy数，happy数定义：按位展开，取平方和，得到的结果在迭代进行相同处理
 * 如果结果为1,则为happy数。
 * 如果结果一直不为1,则不是happy数。
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int sumOfSquareOfDigits = 0;
		while (n != 0) {
			int digit = n % 10;
			sumOfSquareOfDigits += digit * digit;
			n = n / 10;
		}

		if (sumOfSquareOfDigits == 1) {
			return true;
		} else {
			it = sumOfSquareOfDigitsSet.find(sumOfSquareOfDigits);
			if (it == sumOfSquareOfDigitsSet.end()) {
				sumOfSquareOfDigitsSet.insert(sumOfSquareOfDigits);
				return isHappy(sumOfSquareOfDigits);
			} else {
				return false;
			}
		}
	}

private:
	unordered_set<int> sumOfSquareOfDigitsSet;
	unordered_set<int>::iterator it;
};

int main() {
	Solution s;
	cout << s.isHappy(19);
	return 0;
}

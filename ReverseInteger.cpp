/*
 * ReverseInteger.cpp
 *
 *  Created on: 2015年3月27日
 *      Author: netbeen
 */

/*
 * int型逆置算法，运用stack来进行逆置
 * 运用long型来判断int型的溢出
 *
 */

#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x > INT_MAX) {
			return 0;
		} else if (x < -INT_MAX) {
			return 0;
		}
		stack<int> numStack;
		bool isPositive = (x > 0) ? true : false;
		if (!isPositive) {
			x = -x;
		}
		while (x != 0) {
			numStack.push(x % 10);
			x /= 10;
		}
		long result = 0;	//此处long型非常重要，一定要大于int的表示范围，才能检测出int的溢出
		long scale = 1;	//同上
		while (numStack.empty() == false) {
			if (result + (numStack.top()) * scale > INT_MAX) {
				return 0;
			}
			result += numStack.top() * scale;
			numStack.pop();
			scale *= 10;
		}
		return (isPositive == true) ? result : -result;
	}
};

int main() {
	Solution s;
	cout << INT_MAX << endl;
	cout << s.reverse(-2147483648);
	//cout << s.reverse(-123);
	return 0;
}

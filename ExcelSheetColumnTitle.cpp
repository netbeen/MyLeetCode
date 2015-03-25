/*
 * ExcelSheetColumnTitle.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/*
 * 假设十进制数为1000，则八进制数位1750，过程如下：
 * 1000/8=125,余数为0;
 * 125/8=15,余数为5;
 * 15/8=1,余数为7;
 * 1/8=0,余数为1;
 * 你从下往上看这些余数，顺序写出，就是答案1750，要注意的是最后一定要除到0为止，也就是最后一步1/8=0，一定要除到0.
 *
 * 此题类次进制转换问题，画图，总结即可
 */

//#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		stack<char> charStack;
		int remainder;
		while (true) {
			remainder = (n - 1) % 26;
			n = (n - 1) / 26;
			charStack.push(static_cast<char>(65 + remainder));
			if (n == 0) {
				break;
			}
		}
		string result;
		int stackSize = charStack.size();
		for (int i = 0; i < stackSize; i++) {
			result.append(1, charStack.top());
			charStack.pop();
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.convertToTitle(28);
}

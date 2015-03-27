/*
 * StringToInteger(atoi).cpp
 *
 *  Created on: 2015年3月27日
 *      Author: netbeen
 */


/*
 * ATOI算法，leetcode测试用例有点变态，只好照抄威少的了，二轮的时候再来回顾
 *
 */

#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <limits.h>

using namespace std;

class Solution {
public:
	int atoi(string str) {
		int number = 0;
		int sign = 1;
		int i = 0;
		while (i < str.size() && str[i] == ' ')
			i++; // hidden bug
		if (i < str.size()) {
			if (str[i] == '+')
				i++;
			else if (str[i] == '-') {
				sign = -1;
				i++;
			}
		} else {
			return number * sign;
		}
		for (; i < str.size(); ++i) {
			if (str[i] < '0' || str[i] > '9')
				break;
			//number overflow check
			if (number > INT_MAX / 10 || (  (number == INT_MAX / 10) && (str[i] - '0' > INT_MAX % 10)  )  ) {
				return sign == -1 ? INT_MIN : INT_MAX;
			}
			number = number * 10 + str[i] - '0';
		}
		return number * sign;
	}
};

int main() {
	Solution s;
	cout << s.atoi("   -0012a42");
	return 0;
}

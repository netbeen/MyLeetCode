/*
 * RomanToInteger.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */

/*
 * 罗马数字转int。
 * 常识：在大字母左边的小字母只会有连续的一个，比如IX，而不可能有IIX。
 */

#include <iostream>

using namespace std;

class Solution {
public:

	// inline 来加速
	inline int romanMap(const char c) {
		switch (c) {
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'L':
			return 50;
		case 'X':
			return 10;
		case 'V':
			return 5;
		case 'I':
			return 1;
		}

	}

	int romanToInt(string s) {
		int result = 0;
		for(size_t i = 0; i < s.size();i++){
			if((i > 0) && (romanMap(s.at(i)) > romanMap(s.at(i-1)))  ){
				result += romanMap(s.at(i)) - 2 * romanMap(s.at(i-1));		//这里的两倍，是为了将之前已经加上的小字母减掉
			}else{
				result += romanMap(s.at(i));
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.romanToInt("DCXXI");
}

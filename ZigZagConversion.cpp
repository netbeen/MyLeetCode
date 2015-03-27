/*
 * ZigZagConversion.cpp
 *
 *  Created on: 2015年3月27日
 *      Author: netbeen
 */

/*
 * 本题的这个ZigZag样式输出是一个格式化的输出，若指定行数为n，则目标二维表是若干个 n*(n-1)的二维表的横向排列，找出规律，填入字符，最后按行主序扫描二维表，剔除空cell，即可。
 */

#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (s.size() == 0) {
			return s;
		}
		if (nRows == 1) {
			return s;
		}
		int countInEachBox = nRows * 2 - 2;
		int countOfBoxes = (static_cast<int>(s.size()) % countInEachBox == 0) ? static_cast<int>(s.size()) / countInEachBox : static_cast<int>(s.size()) / countInEachBox + 1;
		char ZigZagTabel[nRows][(nRows - 1) * countOfBoxes];
		// 二位数组初始化
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < ((nRows - 1) * countOfBoxes); j++) {
				ZigZagTabel[i][j] = 0;
			}
		}
		// 将字符填入指定的cell中
		for (int i = 0; i < s.size(); i++) {
			if (i % countInEachBox < nRows) {	//填入竖向的字符
				ZigZagTabel[i % countInEachBox][(i / countInEachBox) * (nRows - 1)] = s.at(i);
			} else {	//填入斜向的字符
				int index = i % countInEachBox - nRows;
				ZigZagTabel[nRows - index - 2][(i / countInEachBox) * (nRows - 1) + index + 1] = s.at(i);
			}
		}
		//遍历二位数组求得输出
		string result;
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < ((nRows - 1) * countOfBoxes); j++) {
				if (ZigZagTabel[i][j] != 0) {
					result.append(1, ZigZagTabel[i][j]);
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.convert("A", 1);
	return 0;
}

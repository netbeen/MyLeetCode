/*
 * PascalsTriangle.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */


/*
 *
 * 构造帕斯卡三角，没有什么技术难度，逐行迭代
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {

		int table[numRows][numRows];
		//初始化表格
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numRows; j++) {
				if (j == 0) {
					table[i][j] = 1;
				} else {
					table[i][j] = 0;
				}
			}
		}
		//初始化完毕

		//开始计算并填充帕斯卡三角
		for (int i = 1; i < numRows; i++) {

			for (int j = 1; j < i + 1; j++) {
				table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
			}
		}
		//计算完毕

		//构造结果
		vector<vector<int> > result;
		if (numRows == 0) {
			return result;
		}
		for (int i = 0; i < numRows; i++) {
			vector<int> tempResult;
			for (int j = 0;  j < i + 1 ; j++) {
				tempResult.push_back(table[i][j]);
			}
			result.push_back(tempResult);
		}

		return result;
	}
};

int main() {
	Solution s;
	s.generate(5);
	return 0;
}

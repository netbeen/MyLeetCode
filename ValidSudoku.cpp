/*
 * ValidSudoku.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 统计一个数独是不是有效数独。
 * 分三块来统计，小九宫、行、列
 * 难点：总结出小九宫的通项公式
 */

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int numCount[9];

		//开始统计小九宫有效
		for (int i = 0; i < 9; i++) {
			memset(numCount, 0, sizeof(numCount));
			for (int j = 0; j < 9; j++) {
				if (board.at((i / 3) * 3 + j / 3).at((i * 3) % 9 + j % 3) == '.') {
					continue;
				} else if (numCount[board.at((i / 3) * 3 + j / 3).at((i * 3) % 9 + j % 3) - '0' - 1] > 0)
					return false;
				else {
					numCount[board.at((i / 3) * 3 + j / 3).at((i * 3) % 9 + j % 3) - '0' - 1]++;
				}
			}
		}

		//开始统计行有效
		for (int i = 0; i < 9; i++) {
			memset(numCount, 0, sizeof(numCount));
			for (int j = 0; j < 9; j++) {
				if (board.at(i).at(j) == '.') {
					continue;
				} else if (numCount[board.at(i).at(j) - '0' - 1] > 0)
					return false;
				else {
					numCount[board.at(i).at(j) - '0' - 1]++;
				}
			}
		}

		//开始统计列有效
		for (int i = 0; i < 9; i++) {
			memset(numCount, 0, sizeof(numCount));
			for (int j = 0; j < 9; j++) {
				if (board.at(j).at(i) == '.') {
					continue;
				} else if (numCount[board.at(j).at(i) - '0' - 1] > 0)
					return false;
				else {
					numCount[board.at(j).at(i) - '0' - 1]++;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<vector<char> > board;
	s.isValidSudoku(board);
	return 0;
}

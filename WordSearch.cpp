/*
 * WordSearch.cpp
 *
 *  Created on: 2015年6月7日
 *      Author: netbeen
 */

/*
 * 判断一个char矩阵中是否存在目标字符串，要求各个字符两两相连（上下左右接壤都算相连）
 * 主要思想是遍历整个矩阵，如果找到与第一个字符相同的字符，则以这个字符为起点进行深度优先遍历。
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool exist(const vector<vector<char> >& board, const string word) {
		if (word.empty() || word.empty()) {
			return true;
		}
		if (board.empty() || board.at(0).empty()) {
			return false;
		}
		//used矩阵，用于记录当前整个矩阵中，已经被使用的地方。
		vector<vector<bool> > used(board.size(), vector<bool>(board.at(0).size(), false));

		for (size_t i = 0; i < board.size(); i++) {
			for (size_t j = 0; j < board.at(0).size(); j++) {
				//判断第一字符，并开始DFS
				if (word.at(0) == board.at(i).at(j) && deepSearch(board, word, 0, i, j, used)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	inline bool deepSearch(const vector<vector<char> >& board, const string word, const size_t index, const size_t i, const size_t j, vector<vector<bool> >& used) {
		if (index == word.size()) {
			return true;
		}
		if (i < 0 || i > board.size() - 1 || j < 0 || j > board.at(0).size() - 1 || used.at(i).at(j) == true || board.at(i).at(j) != word.at(index)) {
			return false;
		}
		//设定当前位置为被使用
		used.at(i).at(j) = true;
		//DFS
		bool result = deepSearch(board, word, index + 1, i - 1, j, used) || deepSearch(board, word, index + 1, i + 1, j, used) || deepSearch(board, word, index + 1, i, j - 1, used) || deepSearch(board, word, index + 1, i, j + 1, used);
		//恢复当前位置为未使用，方便以后遍历
		used.at(i).at(j) = false;
		return result;
	}
};

int main() {

	vector<vector<char> > board { { 'a' } };

	Solution s;
	cout << s.exist(board, "a");

	return 0;
}

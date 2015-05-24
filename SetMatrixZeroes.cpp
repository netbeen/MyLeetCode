/*
 * SetMatrixZeroes.cpp
 *
 *  Created on: 2015年5月23日
 *      Author: netbeen
 */

/*
 * 将矩阵中所有的零元素的同行同列全部化成0.
 *
 * 分析：
 * 原始方法：用一个同型备份矩阵，然后记录下0的位置，然后在第二次遍历的时候进行处理。时间复杂度O(m*n)，空间复杂度O(m*n)
 * 进阶方法：用两个向量分别表示行和列，记录下0的位置，在第二次遍历的时候进行处理。时间复杂度O(m*n)，空间复杂度(m+n)
 * BOSS方法：用两个变量表示第一行和第一列是否有0,用第一行和第一列表示表格中的0的位置。时间复杂度O(m*n)，空间复杂度O(1)
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		size_t rowNumber = matrix.size();
		//处理空矩阵
		if (rowNumber == 0) {
			return;
		}

		size_t columnNumber = matrix.at(0).size();
		//处理单行矩阵
		if (rowNumber == 1) {
			bool setZero = false;
			for (int firstRowCell : matrix.at(0)) {
				if (firstRowCell == 0) {
					setZero = true;
					break;
				}
			}
			if (setZero == true) {
				for (int& firstRowCell : matrix.at(0)) {

					firstRowCell=0;
				}
			}
			return;
		}

		//处理单列矩阵
		if (columnNumber == 1) {
			bool setZero = false;
			for (size_t i = 0; i < rowNumber; i++) {
				if (matrix.at(i).at(0) == 0) {
					setZero = true;
					break;
				}
			}
			if (setZero == true) {
				for (size_t i = 0; i < rowNumber; i++) {
					matrix.at(i).at(0) = 0;
				}
			}
			return;
		}

		//记录第一行和第一列的bool变量
		bool firstRowZero = false;
		bool firstColumnZero = false;

		//标记0的位置
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 0; j < matrix.at(0).size(); j++) {

				if (matrix.at(i).at(j) == 0) {
					if (i == 0) {
						firstRowZero = true;
					} else {
						matrix.at(0).at(j) = 0;
					}

					if (j == 0) {
						firstColumnZero = true;
					} else {
						matrix.at(i).at(0) = 0;
					}
				}

			}
		}

		//行方向置零
		for (size_t i = 1; i < rowNumber; i++) {
			if (matrix.at(i).at(0) == 0) {
				for (int& cell : matrix.at(i)) {
					cell = 0;
				}
			}
		}

		//列方向置零
		for (size_t j = 1; j < columnNumber; j++) {
			if (matrix.at(0).at(j) == 0) {
				for (size_t i = 1; i < rowNumber; i++) {
					matrix.at(i).at(j) = 0;
				}
			}
		}

		//第一行是否置零
		if (firstRowZero == true) {
			for (int& firstRowCell : matrix.at(0)) {
				firstRowCell = 0;
			}
		}

		//第一列是否置零
		if (firstColumnZero == true) {
			for (size_t i = 0; i < rowNumber; i++) {
				matrix.at(i).at(0) = 0;
			}
		}

	}
};

int main() {
	Solution s;

	vector<int> row1 { 1,2,3,4 };
	vector<int> row2 { 5,0,5,2 };
	vector<int> row3 { 8,9,2,0 };
	vector<int> row4 { 5,7,2,1 };

	vector<vector<int> > matrix { row1,row2,row3,row4 };

	s.setZeroes(matrix);

	for (vector<int> rowVector : matrix) {
		for (int cell : rowVector) {
			cout << cell << " ";
		}
		cout << endl;
	}

}

/*
 * MinimumPathSum.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: netbeen
 */

/*
 * 给定一个m*n的矩阵，给出一条和最小的路径，从左上走到右下。
 * 典型的动态规划。a[i][j] += min( a[i-1][j] , a[i][j-1] );
 *
 * 注意处理边界情况即可。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() == true) {	//空矩阵情况
			return 0;
		} else if (grid.size() == 1) {	//单行矩阵情况：直接求和返回
			int sum = 0;
			for (int elem : grid.at(0)) {
				sum += elem;
			}
			return sum;
		} else if (grid.at(0).size() == 1) {	//单列矩阵情况：直接求和返回
			int sum = 0;
			for (vector<int> rowVector : grid) {
				sum += rowVector.at(0);
			}
			return sum;
		} else {	// 剩余情况
			size_t columnNum = grid.at(0).size();
			size_t rowNum = grid.size();

			for (size_t columnIndex = 1; columnIndex < columnNum; columnIndex++) {	// 初始化第一行
				grid.at(0).at(columnIndex) += grid.at(0).at(columnIndex - 1);
			}
			for (size_t rowIndex = 1; rowIndex < rowNum; rowIndex++) {	//初始化第一列
				grid.at(rowIndex).at(0) += grid.at(rowIndex - 1).at(0);
			}

			for (size_t currentRowOrColumn = 1; currentRowOrColumn < min(columnNum, rowNum); currentRowOrColumn++) {	//填入剩下的空格
				for (size_t columnIndex = currentRowOrColumn; columnIndex < columnNum; columnIndex++) {
					if (grid.at(currentRowOrColumn - 1).at(columnIndex) < grid.at(currentRowOrColumn).at(columnIndex - 1)) {
						grid.at(currentRowOrColumn).at(columnIndex) += grid.at(currentRowOrColumn - 1).at(columnIndex);
					} else {
						grid.at(currentRowOrColumn).at(columnIndex) += grid.at(currentRowOrColumn).at(columnIndex - 1);
					}
				}
				for (size_t rowIndex = currentRowOrColumn+1; rowIndex < rowNum; rowIndex++) {
					if (grid.at(rowIndex - 1).at(currentRowOrColumn) < grid.at(rowIndex).at(currentRowOrColumn - 1)) {
						grid.at(rowIndex).at(currentRowOrColumn) += grid.at(rowIndex - 1).at(currentRowOrColumn);
					} else {
						grid.at(rowIndex).at(currentRowOrColumn) += grid.at(rowIndex).at(currentRowOrColumn - 1);
					}
				}
			}

			return grid.back().back();	//返回最右下角的元素
		}
	}
};

int main(){
	vector<int> row1{1,2};
	vector<int> row2{1,1};
	vector<vector<int> > grid{row1,row2};

	Solution s;
	cout << s.minPathSum(grid) << endl;

	for(vector<int> rowVector : grid){
		for(int elem : rowVector){
			cout << elem << " ";
		}
		cout << endl;
	}

	return 0;
}

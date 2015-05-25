/*
 * UniquePaths.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: netbeen
 */

/*
 * 给定一个m*n的矩阵，让一个机器人从左上角走到右下角，有多少中路径。每步只能向右或者向下。
 *
 * 典型的动态规划：a[i][j] = a[i-1][j] + a[i][j-1]
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int> > matrix;
    	const int rowNum = m;
    	const int columnNum = n;

    	if(rowNum == 1 || columnNum == 1){
    		return 1;
    	}

    	for(int rowIndex = 0; rowIndex < rowNum; rowIndex++){
    		vector<int> eachRow(columnNum);
    		matrix.push_back(eachRow);
    	}
    	for(int rowIndex = 0; rowIndex < rowNum; rowIndex++){
    		matrix.at(rowIndex).front() = 1;
    	}
    	for(int columnIndex = 0; columnIndex < columnNum; columnIndex++){
    		matrix.front().at(columnIndex) = 1;
    	}
    	for(int curRowAndColumn = 1; curRowAndColumn < min(columnNum,rowNum);curRowAndColumn++){
    		for(int columnIndex = curRowAndColumn; columnIndex<columnNum; columnIndex++){
    			matrix.at(curRowAndColumn).at(columnIndex) = matrix.at(curRowAndColumn-1).at(columnIndex) +matrix.at(curRowAndColumn).at(columnIndex-1);
    		}
    		for(int rowIndex =curRowAndColumn+1; rowIndex < rowNum; rowIndex++ ){
    			matrix.at(rowIndex).at(curRowAndColumn) = matrix.at(rowIndex-1).at(curRowAndColumn)+matrix.at(rowIndex).at(curRowAndColumn-1);
    		}
    	}

    	return matrix.back().back();
    }
};

int main(){
	Solution s;

	cout << s.uniquePaths(2,3);
	return 0;
}

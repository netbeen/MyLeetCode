/*
 * SearchA2DMatrix.cpp
 *
 *  Created on: 2015年4月6日
 *      Author: netbeen
 */

/*
 * 二维矩阵搜索算法。《剑指offer》里看到过，从右上角开始找。
 * 如果小于target，则往下，如果大于target，则往右。
 * 越界则报错。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.empty() || matrix.at(0).empty()){
    		return false;
    	}
    	int rowSize = matrix.size();
    	int columnSize = matrix.at(0).size();
    	int rowIndex = 0;
    	int columnIndex = columnSize-1;
    	while(rowIndex <= rowSize-1 && columnIndex >= 0){
    		if(matrix.at(rowIndex).at(columnIndex) == target){
    			return true;
    		}else if(matrix.at(rowIndex).at(columnIndex) > target){
    			columnIndex--;
    		}else{
    			rowIndex++;
    		}
    	}
    	return false;
    }
};

int main(){
	vector<vector<int> > matrix;
	vector<int> temp;
	temp.push_back(1);
	//temp.push_back(1);
	matrix.push_back(temp);
	Solution s;
	cout << s.searchMatrix(matrix,0);
	return 0;
}

/*
 * Pascal'sTriangleII.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 *
 * 求帕斯卡三角的某一行
 * 先求得整个帕斯卡三角，然后再取某一行。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	int table[rowIndex+1][rowIndex+1];
    	//初始化表格
    	for(int i = 0; i<rowIndex+1;i++){
    		for(int j = 0; j < rowIndex+1;j++){
    			if(j == 0){
    				table[i][j] = 1;
    			}else{
    				table[i][j] = 0;
    			}
    		}
    	}
    	//初始化完毕

    	//开始计算并填充帕斯卡三角
    	for(int i = 1; i < rowIndex +1;i++){
    		for(int j = 1; j < i+1; j++){
    			table[i][j] = table[i-1][j-1] + table[i-1][j];
    		}
    	}
    	//计算完毕

    	//取某一行
    	vector<int> result;
    	for(int i = 0; i < rowIndex +1; i ++){
    		result.push_back(table[rowIndex][i]);
    	}
    	return result;
    }
};

int main(){
	Solution s;
	vector<int> result = s.getRow(21);
	for (int i = 0; i < result.size(); i++){
		cout << result.at(i) << " ";
	}
	return 0;
}

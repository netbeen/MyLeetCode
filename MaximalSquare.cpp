/*
 * MaximalSquare.cpp
 *
 *  Created on: 2015年6月11日
 *      Author: netbeen
 */

/*
 * 在一个矩阵里面寻找一个最大的正方形，这个正方形里面全部都是1,返回正方形的面积
 *
 * 也是DP问题：DP[i][j] = min( dp[i-1][j-1],  dp[i-1][j], dp[i][j-1] ) + 1   //如果这一格是1
 *                            dp[i][j] = 0 //如果这一格是0
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if(matrix.empty() || matrix.at(0).empty()){
    		return 0;
    	}
    	int longestSide = 0;
    	vector<vector<int> > dp(matrix.size(), vector<int>(matrix.at(0).size()));

    	//初始化列
    	for(size_t i = 0; i < matrix.size(); i++){
    		dp.at(i).at(0) = matrix.at(i).at(0) - '0';
    		longestSide = max(longestSide,dp.at(i).at(0));
    	}

    	//初始化行
    	for(size_t j = 1; j < matrix.at(0).size(); j++){
    		dp.at(0).at(j) = matrix.at(0).at(j) - '0';
    		longestSide = max(longestSide,dp.at(0).at(j));
    	}

    	//DP
    	for(size_t i = 1; i < matrix.size(); i++){
    		for(size_t j = 1; j < matrix.at(0).size(); j++){
    			if(matrix.at(i).at(j) == '0'){
    				dp.at(i).at(j) = 0;
    			}else{
    				dp.at(i).at(j) = min(min(dp.at(i-1).at(j), dp.at(i).at(j-1)) , dp.at(i-1).at(j-1))+ 1;
    				longestSide = max(longestSide,dp.at(i).at(j));
    			}
    		}
    	}

    	for(vector<int> vectorElem : dp){
    		for(int elem : vectorElem){
    			cout << elem;
    		}
    		cout << endl;
    	}
    	return longestSide*longestSide;
    }
};

int main(){
	Solution s;
	vector<vector<char> > matrix{{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
	cout << s.maximalSquare(matrix);


	return 0;
}

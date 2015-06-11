/*
 * UniquePathsII.cpp
 *
 *  Created on: 2015年6月11日
 *      Author: netbeen
 */

/*
 * 走迷宫，有多少条不同的路线？其中obstacleGrid表示障碍
 * 基于UniquePath方法，先列出DP公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 改进措施就是加入障碍的判断，令障碍处的dp值为0即可。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if(obstacleGrid.empty() || obstacleGrid.at(0).empty() || obstacleGrid.at(0).at(0) == 1){
    		return 0;
    	}
    	vector<vector<int> >dp(obstacleGrid.size(), vector<int>(obstacleGrid.at(0).size()));
    	dp.at(0).at(0) = 1;

    	for(size_t i = 0; i < obstacleGrid.size(); i++){
    		for(size_t j = 0; j < obstacleGrid.at(0).size(); j++){
    			if(i==0 && j ==0){
    				continue;
    			}
    			if(obstacleGrid.at(i).at(j) == 1){
    				dp.at(i).at(j) = 0;		//障碍处
    			}else{
					int upperNum = (i == 0) ? 0 : dp.at(i - 1).at(j);	//这么写防止越界
					int lefterNum = (j == 0) ? 0 : dp.at(i).at(j - 1);
					dp.at(i).at(j) = upperNum + lefterNum;		//真正的dp
    			}
    		}
    	}
    	return dp.back().back();

    }
};


int main(){
	Solution s;
	vector<vector<int>> obstacleGrid{{0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}

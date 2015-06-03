/*
 * Triangle.cpp
 *
 *  Created on: 2015年6月3日
 *      Author: netbeen
 */

/*
 * 给一个三角型数组：
 * [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*
* 问从顶到底一路上的权值和最小是多少？
*
* 采用动态规划算法：dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + 自身权值
* 实现动态规划算法比较简单，不赘述。
 */

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int dp[triangle.size()+1][triangle.size()+1];
    	for(size_t i = 0; i < triangle.size(); i++){	//少初始化一层：因为dp[triangle.size][0]没用
    		dp[i][i+1] = INT_MAX;
    		dp[i][0] = INT_MAX;
    	}
    	dp[1][1] = triangle.at(0).at(0);
    	for(size_t i = 2; i < triangle.size()+1; i++){
    		for(size_t j = 1; j <= i; j++){
    			dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle.at(i-1).at(j-1);
    		}
    	}
    	int result = INT_MAX;
    	for(size_t i = 1; i < triangle.size()+1; i++){
    		result = min(dp[triangle.size()][i], result);
    	}
    	return result;
    }
};

int main(){
	vector<vector<int> >triangle{{1},{2,3}};

	Solution s;
	cout << s.minimumTotal(triangle);
	return 0;
}

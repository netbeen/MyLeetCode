/*
 * ClimbingStairs.cpp
 *
 *  Created on: 2015年3月30日
 *      Author: netbeen
 */


/*
 * 给定n个台阶，每次可以上一格，也能上两格，求一共有多少中上台阶方式。
 * 动态规划：用一维表进行。dp[i] 等于到第i格台阶，有几种方法。
 * dp[i] = dp[i-1] + dp[i-2]
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(n < 1){
    		return 1;
    	}
    	int dp[n+1];
    	dp[0] = dp[1] = 1;
    	for(int i = 2; i < n+1; i++){
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    	return dp[n];
    }
};

int main(){
	Solution s;
	cout << s.climbStairs(5);
	return 0;
}

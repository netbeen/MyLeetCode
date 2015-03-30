/*
 * MaximumSubarray.cpp
 *
 *  Created on: 2015年3月30日
 *      Author: netbeen
 */

/*
 * 求最大子串的和的算法，运用动态规划。
 * dp[i]的意义：以i结尾的子串的最大和。如果dp[i-1] + A[i] < A[i]，那说明之前的dp[i-1]是负数，加了反而会拖累a[i]，还不如a[i]单干。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int dp[n];
    	dp[0] = A[0];	//初始化

    	//开始动态规划
    	for(int i = 1; i < n; i++){
    		if(dp[i-1] + A[i] > A[i]){
    			dp[i] = dp[i-1] + A[i];
    		}else{
    			dp[i] = A[i];
    		}
    	}

    	//动态规划结束，开始寻找最优解
    	int maxResult = A[0];
    	for(int i = 0; i < n; i++){
    		maxResult = max(maxResult,dp[i]);
    	}
    	return maxResult;
    }
};

int main(){
	Solution s;
	int A[7] = {-2,10,2,3,-1,1,-2};
	cout << s.maxSubArray(A,7);
	return 0;
}

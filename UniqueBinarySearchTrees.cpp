/*
 * UniqueBinarySearchTrees.cpp
 *
 *  Created on: 2015年3月30日
 *      Author: netbeen
 */

/*
 * 给定一个节点数n，求不同的BST树种类有多少？
 * 运用动态规划：dp[i]表示，当有i个节点的时候，有几种不同的BST表示法。
 * 初始化：dp[0]=1; dp[1]=1;显而易见。
 * 动态规划思想，在一堆元素[1,2,...,n]中，挑一个元素作为root，这样很自然将剩下的元素分成两拨，一波在左子树，另一波在右子树。
 * 假设划分元素为k，那么k作为root，左子树有元素[1,2,...k-1]，右子树有元素[k+1,k+2,...n]。
 * 总分法有dp[k-1] * dp[n-(k+1) -1]种。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	if(n == 0){
    		return 1;
    	}else if(n == 1){
    		return 1;
    	}
    	int dp[n+1];		//初始化dp
    	dp[0] = dp[1] = 1;	//dp赋初值

    	//开始规划
    	for(int i = 2; i < n+1; i++){
    		dp[i] = 0;
    		for(int j = 0; j< i; j++){
    			dp[i] += dp[j] * dp[i-j-1];
    		}
    	}
    	return dp[n];
    }
};

int main(){
	Solution s;
	cout << s.numTrees(2);
	return 0;
}

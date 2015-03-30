/*
 * BestTimeToBuyAndSellStock.cpp
 *
 *  Created on: 2015年3月30日
 *      Author: netbeen
 */


#include <vector>
#include <iostream>

/*
 * 计算股票最佳买入卖出时间，规定只允许买卖一次。
 * 一开始考虑使用动态规划，dp[i][j]为从i到j的最大利益.
 * 算法时间复杂度为O(n2)，被leetcode拒掉。记录在maxProfit2。
 *
 * ac方法为O(n)方法。扫描一次表，每次截止当前的最小价格，以及用当前价格-最小价格的最大利益，实时更新。
 * 扫描完成返回。
 */

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	const size_t size = prices.size();
    	int minPrice = INT32_MAX;
    	int maxProfit = 0;
    	for(size_t i = 0; i < size; i++){
    		minPrice = min(prices.at(i) , minPrice);
    		maxProfit = max(prices.at(i)-minPrice, maxProfit);
    	}
    	return maxProfit;
    }

    int maxProfit2(vector<int> &prices) {
    	const size_t vectorSize = prices.size();
    	int dp[vectorSize][vectorSize];
    	for(size_t i = 0; i <vectorSize; i++){
    		dp[i][i] = 0;
    	}
    	for(size_t length = 1; length < vectorSize; length ++){
    		for(int startDay = 0; startDay < vectorSize-length; startDay++){
    			dp[startDay][startDay+length] = max((prices.at(startDay+length) - prices.at(startDay))  ,  (max(dp[startDay][startDay+length-1]  ,  dp[startDay+1][startDay+length])) );
    		}
    	}
    	return dp[0][vectorSize-1];
    }
};

int main(){
	vector<int> prices;
	prices.push_back(0);
	prices.push_back(0);
	prices.push_back(0);
	prices.push_back(0);
	prices.push_back(0);
	Solution s;
	cout << s.maxProfit(prices);

	return 0;
}

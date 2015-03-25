/*
 * BestTimeToBuyAndSellStockII.cpp
 *
 *  Created on: 2015年3月24日
 *      Author: netbeen
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * 股票买涨不买跌，只要相邻两天的差额是正数，就买。如果是负数，就提前一天卖掉。（事后诸葛亮）
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int sumProfit = 0;
    	for(int i = 1; i < prices.size(); i++){
    		if(prices.at(i-1) < prices.at(i)){
    			sumProfit += prices.at(i)-prices.at(i-1);
    		}
    	}
    	return sumProfit;
    }
};

int main(){
	vector<int> prices;
	cout << prices.size();
	Solution s;
	cout << s.maxProfit(prices);
	return 0;
}

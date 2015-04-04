/*
 * GasStation.cpp
 *
 *  Created on: 2015年4月4日
 *      Author: netbeen
 */

/*
 * 加油站问题，如何选择起点，才能保证汽车能够开完一圈。
 * 首先先解出，能不能完成一圈，即构成一个新的vector，pureGas.at(i) = gas.at(i) - cost.at(i);，如果pureGas的和>0，则说明可以完成一圈，否则则不行。（具体证明不明确）
 * 再解出从哪儿开始。思路是这样的，司机会倾向于从某个站出发，沿途把油箱加到峰值，再来慢慢消耗后续的路程。
 * 问题转化为了求一个循环数组的最大子串问题。（之前做过一个非循环数组的最大子串，用的是动态规划）
 * 这里也是一样的方法，只是我用两个相同数组首位相接（原创点），来解决循环的问题。
 * 一个数组的长度为a，那么就组成一个长度为2a的数组，求解最大子串。每次变更起始点的时候都要判断，若起始点超过a，则判定无效，立即返回当前有效起点。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> pureGas(gas.size());
		int pureGasSum = 0;
		for (size_t i = 0; i < gas.size(); i++) {
			pureGas.at(i) = gas.at(i) - cost.at(i);
			pureGasSum += pureGas.at(i);
		}
		if (pureGasSum < 0) {
			return -1;
		} else {
			return findStartOfMaxSubArray(pureGas);
		}
	}

	int findStartOfMaxSubArray(const vector<int> &pureGas) {
		vector<int> doublePureGas(pureGas.size() * 2);
		for (int i = 0; i < 2; i++) {
			for (size_t j = 0; j < pureGas.size(); j++) {
				doublePureGas.at(i * pureGas.size() + j) = pureGas.at(j);
			}
		}
		int dpMaxSum[doublePureGas.size()];
		int maxSumStart = 0;
		dpMaxSum[0] = doublePureGas.at(0);
		for (size_t i = 1; i < doublePureGas.size(); i++) {
			int temp1 = dpMaxSum[i - 1];
			int temp2 = doublePureGas.at(i);
			if (dpMaxSum[i - 1] + doublePureGas.at(i) > doublePureGas.at(i)) {
				dpMaxSum[i] = dpMaxSum[i - 1] + doublePureGas.at(i);
			} else {
				dpMaxSum[i] = doublePureGas.at(i);
				if (i >= doublePureGas.size() / 2) {
					return maxSumStart;
				} else {
					maxSumStart = i;
				}
			}
		}
		return maxSumStart;
	}
};

int main() {
	Solution s;
	int gasArray[] = { 1, 2 };
	int costArray[] = { 2, 1 };
	vector<int> gas(gasArray, gasArray + sizeof(gasArray) / sizeof(int));
	vector<int> cost(costArray, costArray + sizeof(costArray) / sizeof(int));
	cout << s.canCompleteCircuit(gas, cost);
	return 0;
}

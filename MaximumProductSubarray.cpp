/*
 * MaximumProductSubarray.cpp
 *
 *  Created on: 2015年4月5日
 *      Author: netbeen
 */

/*
 * Maximum Sum Subarray的升级版，由于乘积的特殊性，所以在保存最大之的同时，也要保存绝对值最大的负数，这样才能保证结果正确。
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		int result = INT32_MIN;	//初始化返回值
		int dpMaxProduct[n];	//最大积DP
		int dpMaxNagativeProduct[n];	//最大负积DP
		result =dpMaxProduct[0] = dpMaxNagativeProduct[0] = A[0];
		for (int i = 1; i < n; i++) {
			dpMaxProduct[i] = max( max(dpMaxProduct[i-1]*A[i], A[i])  ,   max(dpMaxNagativeProduct[i-1]*A[i], A[i]) );		//维护正积
			dpMaxNagativeProduct[i] = min( min(dpMaxProduct[i-1]*A[i], A[i])  ,   min(dpMaxNagativeProduct[i-1]*A[i], A[i]) );	//维护负积
			result = max(dpMaxProduct[i], result);
		}
		return result;
	}
};

int main() {
	Solution s;
	int A1[] = { 2, 3, -2, 4 };
	cout << s.maxProduct(A1, 4) <<endl;
	return 0;
}


/*
 * HouseRobber.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 强盗抢劫房子，不能抢相邻的房子。求最大利益。
 * 用动态规划，两个动态规划表：
 * dpProfit[i]表示，从0抢到第i间房，最大能获利多少？
 * dpSelect[i]表示，达到dpProfit[i]的时候，有没有抢第i间房
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int> &num) {
		if (num.size() == 0) {
			return 0;
		} else if (num.size() == 1) {
			return num.at(0);
		}
		int dpProfit[num.size()];
		bool dpSelect[num.size()];
		dpProfit[0] = num.at(0);
		dpSelect[0] = true;
		if (num.at(0) < num.at(1)) {
			dpProfit[1] = num.at(1);
			dpSelect[1] = true;
		} else {
			dpProfit[1] = num.at(0);
			dpSelect[1] = false;
		}
		//开始动态规划
		for (size_t i = 2; i < num.size(); i++) {
			if (dpSelect[i - 1] == true) {	//若上次抢了第i-1间房
				if (dpProfit[i - 1] < dpProfit[i - 2] + num.at(i)) {	//判断要不要抢第i间房
					dpProfit[i] = dpProfit[i - 2] + num.at(i);
					dpSelect[i] = true;
				} else {
					dpProfit[i] = dpProfit[i - 1];
					dpSelect[i] = false;
				}
			}else{	//若上次没有抢第i-1间房
				dpProfit[i] = dpProfit[i-1] + num.at(i);	//必抢第i间房
				dpSelect[i] = true;
			}
		}
		return dpProfit[num.size() - 1];
	}
};

int main() {
	Solution s;
	/*int array1[] = { 7, 8, 6, 5, 7 };
	vector<int> num1(array1, array1 + 5);
	cout << s.rob(num1) << endl;

	vector<int> num2;
	cout << s.rob(num2) << endl;*/

	int array3[] = { 1, 3, 1 };
	vector<int> num3(array3, array3 + 3);
	cout << s.rob(num3) << endl;

	return 0;
}

/*
 * HouseRobberII.cpp
 *
 *  Created on: 2015年6月11日
 *      Author: netbeen
 */


/*
 * 强盗抢房子升级版：环形街道。不能抢相邻的房子。求最大值。
 * 典型动态规划：profit[i] = max( profit[i-1] , profit[i-2]+nums[i] )
 *
 * 对于环形的问题，则可以这么解决：做两次动态规划，第一次限定一定要抢第一间，第二次限定一定不能抢第一间
 */

#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		} else if (nums.size() == 1) {
			return nums.at(0);
		} else if (nums.size() == 2) {
			return max(nums.at(0), nums.at(1));
		}else{
			return max(this->rub1st(nums),this->notRub1st(nums));
		}

	}

private:
	int rub1st(const vector<int>& nums) {
		vector<int> profit(nums.size());
		profit.at(0) = nums.at(0);
		profit.at(1) = max(nums.at(0), nums.at(1));
		for (size_t i = 2; i < nums.size() - 1; i++) {
			profit.at(i) = max(profit.at(i - 1), profit.at(i - 2) + nums.at(i));
		}
		return profit.at(nums.size() - 2);
	}

	int notRub1st(const vector<int>& nums) {
		vector<int> profit(nums.size());
		profit.at(0) = 0;
		profit.at(1) = nums.at(1);
		for (size_t i = 2; i < nums.size(); i++) {
			profit.at(i) = max(profit.at(i - 1), profit.at(i - 2) + nums.at(i));
		}
		return profit.back();
	}
};

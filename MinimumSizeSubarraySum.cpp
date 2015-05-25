/*
 * MinimumSizeSubarraySum.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: netbeen
 */

/*
 * 给定一个vector，里面包含正数。返回和>=s的最小长度。
 * 例如：[2,3,1,2,4,3]，s=7
 * 则[4,3]为最小串，返回2
 *
 * 若不存在，则返回0.
 *
 * 分析：正是由于全部都是正数，所以可以使用双index法，
 * 当两个index之间的和< s的时候，则highIndex右移
 * 当>=s的时候，lowIndex右移。
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() == true) {
			return 0;
		}
		int currentSum = nums.at(0);
		size_t lowIndex = 0;
		size_t highIndex = 0;
		int minLen = INT_MAX;
		while (true) {

			//当两个index之间的和< s的时候，则highIndex右移
			if (currentSum < s) {
				highIndex++;
				if (highIndex < nums.size()) {
					currentSum += nums.at(highIndex);
				} else {
					break;
				}

			//当>=s的时候，lowIndex右移。
			} else if (currentSum >= s) {
				minLen = (static_cast<int>(highIndex) - static_cast<int>(lowIndex) + 1 < minLen) ? static_cast<int>(highIndex) - static_cast<int>(lowIndex) + 1 : minLen;
				lowIndex++;
				currentSum -= nums.at(lowIndex - 1);
			}
		}
		return (minLen == INT_MAX) ? 0 : minLen;
	}
};

int main() {
	vector<int> nums { 1, 1 };
	Solution s;
	cout << s.minSubArrayLen(3, nums);

	return 0;
}

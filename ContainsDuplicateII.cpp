/*
 * ContainsDuplicateII.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: netbeen
 */

/*
 * 要求判断一个数组中有无满足条件的重复元素。条件：nums[i] = nums[j] && j-i <= k
 * 其中k是给定的。
 *
 * 方法：滑动窗口法。
 * 第一阶段：窗口增长期，直到溢出或者窗口长度达到k
 * 第二阶段：窗口平移期，进一个出一个，并判断。
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() < 2) {
			return false;
		}
		unordered_set<int> hashSet;
		int lowIndex = 0;
		int highIndex = 0;

		//窗口增长期
		while (highIndex - lowIndex <= k && highIndex < nums.size()) {
			unordered_set<int>::iterator it = hashSet.find(nums.at(highIndex));
			if (it != hashSet.end()) {
				return true;
			} else {
				hashSet.insert(nums.at(highIndex));
			}
			highIndex++;
		}

		//窗口平移期
		while (highIndex < nums.size()) {
			hashSet.erase(nums.at(lowIndex));
			lowIndex++;
			unordered_set<int>::iterator it = hashSet.find(nums.at(highIndex));
			if (it != hashSet.end()) {
				return true;
			} else {
				hashSet.insert(nums.at(highIndex));
			}
			highIndex++;
		}
		return false;
	}
};

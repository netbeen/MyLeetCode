/*
 * FindMinimumInRotatedSortedArray.cpp
 *
 *  Created on: 2015年6月14日
 *      Author: netbeen
 */

/*
 * 给定一个有序的数组，有可能被旋转~比如(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).返回最小元素。
 *
 * 最小元素这种事情，笨办法就是O(n)的扫描，但是既然有序，就要用二分。
 * 首先要排除未被旋转的情况，所以判断第一元素是否小于最后元素，若成立，则说明数组未被旋转，直接返回第一元素.
 *
 * 若上述判断不成立，则说明被旋转了，则开始二分。
 */

#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1) {	//排除单元素情况
			return nums.front();
		}
		if (nums.front() < nums.back()) {	//排除有序未被旋转情况
			return nums.front();
		}
		int topIndex = 0;
		int tailIndex = nums.size() - 1;
		while (true) {	//开始二分
			if (topIndex == tailIndex - 1) {
				return nums.at(tailIndex);
			} else {
				int midIndex = (topIndex + tailIndex) / 2;
				if (nums.at(midIndex) > nums.at(topIndex)) {
					topIndex = midIndex;
				} else {
					tailIndex = midIndex;
				}
			}
		}
	}
};

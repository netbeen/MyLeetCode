/*
 * KthLargestElementInAnArray.cpp
 *
 *  Created on: 2015年6月14日
 *      Author: netbeen
 */

/*
 * 寻找第k大的元素，先排序，在定位，没技术含量！
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	sort(nums.begin(),nums.end());
    	return nums.at(nums.size()-k);
    }
};

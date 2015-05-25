/*
 * ContainsDuplicate.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: netbeen
 */

/*
 * 判断数组中的元素是否有重复。
 * 先排序，然后遍历，每一个和前一个比较，看看是否会相同。
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.size() < 2){
    		return false;
    	}
    	std::sort(nums.begin(), nums.end());
    	for(size_t index = 1; index < nums.size(); index++){
    		if(nums.at(index-1) == nums.at(index)){
    			return true;
    		}
    	}
    	return false;
    }
};

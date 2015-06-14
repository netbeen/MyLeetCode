/*
 * FindPeakElement.cpp
 *
 *  Created on: 2015年6月14日
 *      Author: netbeen
 */

/*
 * 找到顶尖元素，并假设a[-1]和a[n]都为负无穷
 *
 * 分析：由于两个端点为负无穷，说明顶点一定存在。再者，由于只要返回任意一个顶尖元素即可，所以就采用遍历，即返回第一个顶尖元素。
 * 遍历数组，看看a[i+1] > a[i]是否成立，若不成立，则说明i为顶尖坐标。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	for(size_t index = 0; index < nums.size()-1; index++){
    		if(nums.at(index) > nums.at(index+1)){
    			return index;
    		}
    	}
    	return nums.size()-1;
    }
};

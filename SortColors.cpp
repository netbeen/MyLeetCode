/*
 * SortColors.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: netbeen
 */

/*
 * 给定一个数组，用012三个数字来表示红蓝白三色，为三种颜色排序，要求顺序：红、蓝、白。
 *
 * 由于已知数域：剩下的就教给计数排序了。
 * A轮：统计各个数字的出现次数。
 * B轮：将A论的数字叠加，换算为最后一个元素的出现位置
 * C轮：将该元素放到指定的位置，并且将B轮数组--
 */

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
    	vector<int> colorCount(3);
    	//A轮
    	for(int elem : nums){
    		colorCount.at(elem)++;
    	}

    	//B轮
    	for(size_t index = 1; index < colorCount.size(); index++){
    		colorCount.at(index) += colorCount.at(index-1);
    	}

    	vector<int> result(nums.size());

    	//C轮
    	for(int elem : nums){
    		result.at(colorCount.at(elem) - 1) = elem;
    		colorCount.at(elem)--;
    	}
    	nums.swap(result);
    }
};

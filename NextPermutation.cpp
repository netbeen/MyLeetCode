/*
 * NextPermutation.cpp
 *
 *  Created on: 2015年6月3日
 *      Author: netbeen
 */

/*
 * 给一个排列，求比这个排列再一点的排列。例如给定{1,1,5}，返回{1,5,1}
 * 如果排列已经最大，则返回最小排列。例如给定{3,2,1}，返回{1,2,3}
 *
 * 分析：排列问题。先从后往前扫描，直到扫到第一个”顺序“，例如nums[i-1] < nums[i]
 * 则在nums[i]到nums.end里面找到一个比nums[i-1]大的最小值，将这个值与nums[i-1]交换，最后重新排列nums[i]至nums.end之间的元素
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int currentIndex = nums.size()-1;
    	while(currentIndex > 0){
    		if(nums.at(currentIndex) <= nums.at(currentIndex - 1)){
    			currentIndex--;
    		}else{
    			int smallIndex = this->findSmallIndex(nums , currentIndex ,nums.at(currentIndex-1));
    			swap(nums.at(currentIndex-1), nums.at(smallIndex));
    			sort(nums.begin() + currentIndex,nums.end() );
    			return;
    		}
    	}
    	sort(nums.begin(),nums.end() );
    	return;
    }

private:
    int findSmallIndex(vector<int>& nums, const int startPos,const int target){
    	int smallIndex = startPos;
    	for(size_t i = startPos; i < nums.size(); i++){
    		if(nums.at(i) < nums.at(smallIndex) && nums.at(i) > target){
    			smallIndex = i;
    		}
    	}
    	return smallIndex;
    }
};

int main(){
	vector<int> nums{2,3,1};

	Solution s;
	s.nextPermutation(nums);

	for(int elem : nums){
		cout << elem;
	}

	return 0;
}

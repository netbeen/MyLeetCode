/*
 * SearchForARange.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: netbeen
 */

/*
 * 给定 [5, 7, 7, 8, 8, 10] ，target为8。返回[3,4]
 *
 * 先通过二分查找定位锚点（随便某一个8），然后确定边界。
 * 边界确定也是采用二分查找，注意寻找不变量：就是两个指针，其中锚点永远在8的范围内，直到锚点与边界游标重合，迭代结束。
 *
 * 新知识：向上取整函数：ceil(), 需要包含<cmath>
 */

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty() == true) {
			return vector<int>(2,-1);
		}
		int searchIndex = this->binarySearch(nums,target);
		if(searchIndex == -1){
			return vector<int>(2,-1);
		}
		int leftBoundary = this->findLeftBoundary(nums, searchIndex, 0);
		int rightBoundary = this->findRightBoundary(nums,searchIndex,nums.size()-1);
		vector<int> result{leftBoundary,rightBoundary};
		return result;


	}

	int findLeftBoundary(const vector<int>& nums, int anchor, int leftIndex){
		while(anchor != leftIndex){
			int mid = (anchor + leftIndex)/2;
			if(nums.at(mid) == nums.at(anchor)){
				anchor = mid;
			}else{
				leftIndex = mid+1;
			}
		}
		return anchor;
	}

	int findRightBoundary(const vector<int>& nums, int anchor, int rightIndex){
			while(anchor != rightIndex){
				int mid = ceil(static_cast<float>(anchor + rightIndex)/2);
				if(nums.at(mid) == nums.at(anchor)){
					anchor = mid;
				}else{
					rightIndex = mid-1;
				}
			}
			return anchor;
		}

	int binarySearch(const vector<int>& nums, int target) {
		if (nums.empty() == true) {
			return -1;
		}
		int lowIndex = 0;
		int highIndex = nums.size() - 1;
		while (highIndex > lowIndex) {
			int mid = (highIndex + lowIndex) / 2;
			if (nums.at(mid) == target) {
				return mid;
			} else if (nums.at(mid) > target) {
				highIndex = mid - 1;
			} else {
				lowIndex = mid + 1;
			}
		}
		if(nums.at(lowIndex) != target){
			return -1;
		}else{
			return lowIndex;
		}
	}
};

int main(){
	vector<int> nums{1};
	Solution s;
	vector<int> result = s.searchRange(nums,1);
	for(int elem : result){
		cout << elem << " ";
	}

	return 0;
}

/*
 * Subsets.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: netbeen
 */

/*
 *给定一个集合【1,2,3】
 * 要求给出所有的子集
 * 【】
 * 【1】
 * [2]
 * [3]
 * [12]
 * [23]等等。。。。。
 *
 * 分析，对于3个元素，一共有2^3=8个子集。
 * 然后for循环从0-7，按位展开，分别映射，就可以得到结果
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int> > result;
    	if(nums.empty()){
    		return result;
    	}
    	//先排序
    	std::sort(nums.begin(),nums.end());

    	//再去重复元素
    	this->deleteDuplicateElem(nums);

    	//for 0-7，一共8个子集
    	for(int counter = 0; counter < pow(2,nums.size()) ;counter++){

    		int tempCounter = counter;
    		vector<int> temp;

    		// for 0-2，一共3位
    		for(size_t index = 0; index < nums.size(); index++){

    			if ((tempCounter & 0x1 ) == 1){
    				temp.push_back(nums.at(index));
    			}
    			tempCounter = tempCounter >> 1;

    		}
    		result.push_back(temp);
    	}
    	return result;
    }

private:
    void deleteDuplicateElem(vector<int>& nums){
    	if(nums.size() == 1){
    		return;
    	}
    	for(size_t index = nums.size()-1; index > 0; index--){
    		if(nums.at(index) == nums.at(index-1)){
    			nums.erase(nums.begin()+index);
    		}
    	}
    }
};

int main(){
	Solution s;

	vector<int> nums{1,2};
	vector<vector<int> > result = s.subsets(nums);
	cout << result.size();


}

/*
 * CombinationSum.cpp
 *
 *  Created on: 2015年6月15日
 *      Author: netbeen
 */

/*
 * 给定一个[2, 2, 3,6,7] ，再给一个target=7，要求给出所有组合，是相加的结果=7。其中每个元素可以使用多次。
 *
 * 分析：由于每个元素可以使用多次，则重复的元素就没有意义，先排序，在去重。
 * 然后构建一个helper函数，用于递归检查。
 *
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if(candidates.empty()){
			return result;
		}
		sort(candidates.begin(), candidates.end());	//排序
		//	去重
		for(size_t index = candidates.size()-1; index >0; index--){
			if(candidates.at(index) == candidates.at(index-1)){
				candidates.erase(candidates.begin()+index);
			}
		}
		vector<int> item;
		this->helper(candidates, target, 0, item, result);
		return result;
	}

private:
	void helper(vector<int>& candidates, int target, int startIndex, vector<int>& nowItem, vector<vector<int>>& result){
		if(target < 0){
			return;
		}else if(target == 0){
			result.push_back(nowItem);
			return;
		}else{
			for(size_t i = startIndex; i<candidates.size(); i++){
				nowItem.push_back(candidates.at(i));	//加入新元素
				helper(candidates, target-candidates.at(i), i, nowItem, result);	//检查下一种可能性
				nowItem.pop_back();	//回退至之前的状态
			}
		}
	}
};

int main(){
	vector<int> candidates{1,2};
	Solution s;
	vector<vector<int>> result = s.combinationSum(candidates,3);
	for(vector<int> vectorElem : result){
		for(int elem : vectorElem){
			cout << elem;
		}
		cout << endl;
	}

	return 0;
}

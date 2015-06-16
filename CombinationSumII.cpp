/*
 * CombinationSumII.cpp
 *
 *  Created on: 2015年6月16日
 *      Author: netbeen
 */

/*
 * CombinationSumII于之前的CombinationSum思路基本一样，只是每个元素只能使用一次了，下面的注释都是直接复制来的：
 * 不过，要修改几点：由于只能出现一次了，重复元素就有用了，因此，删掉去重环节。
 * 由于每次递归不能再递归自己，则要求，传入的参数为i+1
 * 上述两点后：提交，发现结果集里会有重复元素。一想，对！由于没有了去重，重复元素会好几次进入递归，会出现很多重复结果集，
 * 因此需要在进入递归前进行判断，如果前面的数字与自己相同，则不允许跳过递归
 */


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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if(candidates.empty()){
			return result;
		}
		sort(candidates.begin(), candidates.end());	//排序
		vector<int> item;
		this->helper(candidates, target, 0, item, result);
		return result;
	}

private:
	void helper(vector<int>& candidates, int target, size_t startIndex, vector<int>& nowItem, vector<vector<int>>& result){
		if(target < 0){
			return;
		}else if(target == 0){
			result.push_back(nowItem);
			return;
		}else{
			for(size_t i = startIndex; i<candidates.size(); i++){
				if(i>startIndex && candidates.at(i)==candidates.at(i-1))
					continue;
				nowItem.push_back(candidates.at(i));	//加入新元素
				helper(candidates, target-candidates.at(i), i+1, nowItem, result);	//检查下一种可能性
				nowItem.pop_back();	//回退至之前的状态
			}
		}
	}
};

int main(){
	vector<int> candidates{1,1,1,2};
	Solution s;
	vector<vector<int>> result = s.combinationSum2(candidates,3);
	for(vector<int> vectorElem : result){
		for(int elem : vectorElem){
			cout << elem;
		}
		cout << endl;
	}

	return 0;
}

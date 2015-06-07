/*
 * JumpGame.cpp
 *
 *  Created on: 2015年6月7日
 *      Author: netbeen
 */

/*
 * 题目:给一个数组，每一个值就是在这个位置能往前跳跃的最远距离。问：能不能跳到终点。
 * 例如：	A = [2,3,1,1,4], return true.
 * 				A = [3,2,1,0,4], return false.
 *
 * 分析：使用一个类贪心算法
 * 建立一个数组，保存局部最优值。局部最优值就是当前格子能跳到的最远地方：local = A[i] +i
 * 再建立一个全局最优值。global保存当前能跳到的最远方案的值：global = max(local, global)
 *
 * 在遍历数组，若当前i超过了global，则说明这个点到不了，则返回false
 * 若走完数组，则返回true
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	vector<int> localOptimal(nums.size());
    	int globalOptimal = 0;
    	for(size_t i = 0; i < nums.size(); i++){
    		if(globalOptimal < i){
    			return false;
    		}else{
    			localOptimal.at(i) = i + nums.at(i);
    			globalOptimal = max(localOptimal.at(i), globalOptimal);
    		}
    	}
    	return true;
    }
};

/*
 * TwoSum.cpp
 *
 *  Created on: 2015年3月26日
 *      Author: netbeen
 */


#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * 使用C++11的新特性，unordered_map，即hash表。需要配置编译器选项为-std=c++11，预编译器的-std=c++11选项也要同时添加（否则能运行，但是IDE提示代码出错，比较难看）
 * 难点1：测试用例[0,4,3,0], target = 0
 * 难点2：测试用例[3,4,2], target = 6
 * 由于unordered_map不支持重复元素，因此第二个元素进入后会将第一个元素覆盖：
 * 第1个零读入哈希表后，hashMap[0]=0
 * 第2个零读入哈希表后，hashMap[0]=3
 *
 * target=0, i=0, numbers[i]=0, searchTarget=0
 *
 * it->first是取key的值
 * it->second 是取value的值
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> result;
    	unordered_map<int, int> hashMap;	//<key, value> = <number, index>
    	for(int i = 0; i < static_cast<int>(numbers.size());i++){
    		hashMap[numbers.at(i)] = i;
    	}
    	for(int i = 0; i < static_cast<int>(numbers.size());i++){
    		int searchTarget = target - numbers.at(i);
    		unordered_map<int,int>::iterator it = hashMap.find(searchTarget);
    		if(it != hashMap.end()){
    			if(it->second == i){		//用来对付难点2：测试用例[3,4,2], target = 6
    				continue;
    			}
    			result.push_back(i +1);
    			result.push_back(hashMap[searchTarget]+1);
    		}
    	}
    	return result;
    }
};

int main(){
	Solution s;
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(0);

	vector<int> result = s.twoSum(numbers,0);
	for(int i = 0; i < result.size(); ++i){
		cout<<result[i ] <<endl;
	}
}

/*
 * MajorityElement.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 * 找出那一个占绝大多数的元素，数量>n/2
 * 本次使用unordered_map来进行统计，找出最大值，并返回那个元素即可。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &num) {
		unordered_map<int, int> hashMap;	//新建undered_map
		int maxCount = 0;
		int maxNum = 0;
		for (int i = 0; i < num.size(); i++) {
			unordered_map<int, int>::iterator it = hashMap.find(num.at(i));
			if (it != hashMap.end()) {		//如果元素存在
				hashMap.at(num.at(i))++;}
			else {		//如果元素不存在
				hashMap.insert(pair<int, int>(num.at(i), 1));
			}
			if (hashMap.at(num.at(i)) > maxCount) {	//更新标志位
				maxCount = hashMap.at(num.at(i));
				maxNum = num.at(i);
			}
		}
		return maxNum;
	}
};

int main() {
	Solution s;
	vector<int> num;
	num.push_back(1);
	cout << s.majorityElement(num);
	return 0;
}

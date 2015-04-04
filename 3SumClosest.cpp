/*
 * 3SumClosest.cpp
 *
 *  Created on: 2015年4月4日
 *      Author: netbeen
 */

/*
 * 给定一个vector和target，选定三个数，让三个数只和最接近target，返回这个和。
 * 先对vector进行排序，
 * 然后，选定第一个数，假设坐标在i，将后续的数用两个指针进行夹逼，直至找到最接近的那个组合。
 * 在将第一个数向后遍历。
 * 时间复杂度O(n^2)
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int closest = INT32_MAX;
		int closestSum = 0;
		for(size_t i = 0; i < num.size()-2;i++){
			int low = i+1;
			int high = num.size()-1;
			while(low < high){
				if(abs(num.at(i) + num.at(low) + num.at(high) - target) < abs(closest)){
					closest = num.at(i) + num.at(low) + num.at(high) - target;
					closestSum = num.at(i) + num.at(low) + num.at(high);
				}
				if(num.at(i) + num.at(low) + num.at(high) - target > 0){
					high--;
				}else{
					low++;
				}
			}
		}
		return closestSum;
	}
};

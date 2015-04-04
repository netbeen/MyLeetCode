/*
 * 3Sum.cpp
 *
 *  Created on: 2015年4月3日
 *      Author: netbeen
 */

/*
 * 求解3sum问题，要求从无序数组中找出所有的三元组，这些三元组的和为0,且必须为递增顺序。
 * 关键步骤，先排序，然后用三个指针进行遍历。
 * 时间复杂度O(n^3)
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		if(num.size() < 3){
			return result;
		}
		sort(num.begin(), num.end());
		for (size_t i = 0; i < num.size() - 2; i++) {
			if (num.at(i) > 0) {
				break;
			}
			for (size_t j = i + 1; j < num.size() - 1; j++) {
				if (num.at(i) + num.at(j) > 0) {
					break;
				}
				for (size_t k = j + 1; k < num.size(); k++) {
					if (num.at(i) + num.at(j) + num.at(k) == 0) {
						vector<int> elementVector;
						elementVector.push_back(num.at(i));
						elementVector.push_back(num.at(j));
						elementVector.push_back(num.at(k));
						result.push_back(elementVector);
					} else if (num.at(i) + num.at(j) + num.at(k) > 0) {
						break;
					}
					while (k + 1 < num.size() && num.at(k + 1) == num.at(k)) {
						k++;
					}
				}
				while (j + 1 < num.size()-1 && num.at(j + 1) == num.at(j)) {
					j++;
				}
			}
			while (i + 1 < num.size()-2 && num.at(i + 1) == num.at(i)) {
				i++;
			}
		}
		return result;
	}
};

int main() {

	return 0;
}

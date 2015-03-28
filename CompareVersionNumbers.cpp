/*
 * CompareVersionNumbers.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 * 比较两个版本号的大小，要得就是小心仔细，字符串题目都要注意细节。
 * 每次都比较两个小数点之间的数字，大就大，小就小。如果一样，再比较下一组小数点之间的数字
 */

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		size_t cursor1 = 0;		//当前的有效起始游标
		size_t cursor2 = 0;
		while ((cursor1 < version1.size()) && (cursor2 < version2.size())) {	//如果游标没有到string的尾部
			size_t foundDot1 = version1.find('.', cursor1);	//在有效区间寻找小数点
			size_t foundDot2 = version2.find('.', cursor2);
			int v1 = stoi(string(version1, cursor1, foundDot1));	//生成两个int数（两个小数点之间的数字）
			int v2 = stoi(string(version2, cursor2, foundDot2));
			if (v1 > v2) {		//比较大小，若大
				return 1;
			} else if (v1 < v2) {		//若小
				return -1;
			} else {		//若相同
				if (foundDot1 != version1.npos) {
					cursor1 = foundDot1 + 1;	//移动有效游标至小数点后一位，准备再次循环
				} else {
					cursor1 = version1.size();	//移动游标至字符串末尾，因为后面没有小数点了
				}
				if (foundDot2 != version2.npos) {
					cursor2 = foundDot2 + 1;
				} else {
					cursor2 = version2.size();
				}
			}
		}

		//若version1的游标到末尾了，version2的游标没有到末尾，并且version2后续的有效int不为0的时候，判version2大
		if((cursor1 == version1.size()) &&  (cursor2 != version2.size())  && stoi(string(version2, cursor2, version2.npos)) != 0  ){
			return -1;
		}else if((cursor1 != version1.size()) &&  (cursor2 == version2.size()) && stoi(string(version1, cursor1, version1.npos)) != 0  ){
			return 1;
		}else{
			return 0;
		}
	}
};

int main() {
	Solution s;
	cout << s.compareVersion("1.0", "1") << endl;
	return 0;
}

/*
 * RemoveDuplicatesFromSortedArray.cpp
 *
 *  Created on: 2015年4月1日
 *      Author: netbeen
 */

/*
 * 在一个排好序的数组中，剔除重复元素，要求只能使用O(1)空间
 * 使用两个指针，一个指向有效数组的末尾，另一个指向当前扫描的数，一趟扫描即可得到结果。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 0){
    		return 0;
    	}
    	int validTail = 0;
    	for(int cursor = 1; cursor < n ; cursor ++){
    		if(A[cursor] != A[validTail]){
    			validTail ++;
    			A[validTail] = A[cursor];
    		}
    	}
    	return validTail+1;
    }
};

int main(){
	Solution s;
	int A1[3] = {1,1,2};
	cout << s.removeDuplicates(A1,3) << endl;

	int A2[0] = {};
	cout << s.removeDuplicates(A2,0) << endl;

	int A3[3] = {1,1,1};
	cout << s.removeDuplicates(A3,3) << endl;
}

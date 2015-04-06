/*
 * SearchInsertPosition.cpp
 *
 *  Created on: 2015年4月6日
 *      Author: netbeen
 */

/*
 * 给定一个有序数组和插入元素，求插入位置。
 * 数组有序，必然使用二分查找。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if(n == 0){
    		return 0;
    	}
    	int low = 0;
    	int high = n-1;
    	while(low <= high){
    		int middle = (low+high)/2;
    		if(A[middle] == target){
    			return middle;
    		}else if(A[middle] > target){
    			high = middle -1;
    		}else{
    			low = middle +1;
    		}
    	}
    	return low;
    }
};

int main(){
	int A[] = {1,3};
	Solution s;
	cout << s.searchInsert(A,2,2);
	return 0;
}

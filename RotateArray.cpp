/*
 * RotateArray.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */

/*
 * 实现数组的循环右移，运用两次逆置法:（所谓的两次，是指对每个元素，都会实施两次逆置。整体算法有3次逆置）
 * 首先将A[0,n-k-1]逆置，再将A[n-k,n-1]逆置。（将A分两部分逆置）
 * 再将A整体逆置，就能得到结果。
 */

#include <iostream>

using namespace std;

class Solution {
public:
	//逆置函数
	void reverse(int nums[], int start, int end){
		while(start < end){
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start ++;
			end --;
		}
	}


	//两次逆置法
    void rotate(int nums[], int n, int k) {
    	k %= n;
    	reverse(nums, 0, n-k-1);
    	reverse(nums, n-k,n-1);
    	reverse(nums, 0, n-1);
    }
};

int main(){
	return 0;
}

/*
 * SingleNumber.cpp
 *
 *  Created on: 2015年3月24日
 *      Author: netbeen
 */


#include <iostream>
/**
 * 本算法运用异或运算，即用相同的数同时对0进行异或,两次之后还是0
 * 即(XORNum ^ x) ^x = XORNum
 * 随后剩下的就是唯一落单的数了。AC。
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int XORNum = 0;
    	for(int i = 0; i < n; i ++){
    		XORNum ^= A[i];
    	}
    	return XORNum;
    }
};

int main(){
	Solution s;
	int A[3] = {1,2,1};
	std::cout << s.singleNumber(A,3);
	return  0;
}

/*
 * SingleNumberII.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */


/*
 * 在一堆三三成对的数组中，找到那个唯一的落单的数。
 * 位运算：原理，按2进制展开，如果每一个bit上1的数目不能被3整除，说明这一位是那个落单数的组成部分。
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
    	int result = 0;
    	// 按位处理
    	for(int bitIndex = 0; bitIndex < 32; bitIndex++){
    		int thisBitOnesCount = 0;
    		for(int numIndex = 0; numIndex < n; numIndex++){
    			if((A[numIndex] >> bitIndex) & 1){
    				thisBitOnesCount++;
    			}
    		}
    		if(thisBitOnesCount%3 != 0){
    			result += 1 << bitIndex;	//更新结果
    		}
    	}
    	return result;
    }
};

int main(){
	Solution s;
	int array1[] = {1,1,1,2};
	cout << s.singleNumber(array1,4);

	return 0;
}

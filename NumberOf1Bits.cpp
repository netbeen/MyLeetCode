/*
 * NumberOf1Bits.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/*
 * uint32_t类型包含在stdint.h头文件中
 * 只要有int商不为0,则继续除以2,统计余数为1的数目。
 */

#include <stdint.h>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int remainder = 0;
    	int sum = 0;
    	while(true){
    		remainder = n%2;
    		sum += remainder;
    		n /= 2;
    		if(n == 0){
    			break;
    		}
    	}
    	return sum;
    }
};

int main(){
	Solution s;
	cout << s.hammingWeight(11) << endl;
	return 0;
}

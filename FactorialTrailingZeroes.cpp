/*
 * FactorialTrailingZeroes.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 *
 * 计算n阶乘的最后连续0的个数。由于要求时间复杂度为O(logn)，所以不能用先阶乘再%10的做法。
 * 通过观察发现，只有2*5才能出现一个0,而2又远远多于5,因此只要计算n中含有多少个5因子即可。
 * 注意由于25会提供2个5,125会提供3个5,所以都要算上。
 * 先除一遍5,再除25,这样25所提供的第一个5已经在第一遍加上了，所以再加上25的，就刚好两个5.以此类推。
 */

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
    	int sum = 0;
    	for(int i = 1;pow(5,i) <= n; i++ ){
    		sum += n/pow(5,i);
    	}
    	return sum;
    }
};

int main(){
	Solution s;
	cout << s.trailingZeroes(5);
	return 0;
}

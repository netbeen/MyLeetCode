/*
 * ReverseBits.cpp
 *
 *  Created on: 2015年4月1日
 *      Author: netbeen
 */


/*
 * 整型数的二进制逆序，比如将001010转换为010100.
 *通过位运算，
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	for(int i = 0; i < 16; i ++){
    		if(((n >> i)&1) ^( (n >> (31-i))&1) ){	//判断第i位和第31-i位是否相同，相同就不同换了。
    			n = n^(1 << i | 1<<(31-i));	//构造一个全0,只有第i位和第31-i位为1的数，然后与n异或。
    		}
    	}
    	return n;
    }
};

int main(){
	Solution s;
	//cout << setw(8);
	cout << "origin: 43261596=" << hex << (43261596) << endl;
	cout << "                                  "<<dec<< s.reverseBits(43261596)<< endl;

}

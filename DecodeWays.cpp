/*
 * DecodeWays.cpp
 *
 *  Created on: 2015年4月5日
 *      Author: netbeen
 */

/*
 * 求解不同的编码方式。动态规划法。
 * 判断当前字符，如果新字符可以和独立表示，那么模式一成立。如果新字符可以和上一个字符凑成一个字符，模式二成立。
 * 一下为00-99的表示，第一位为i-1位置的，第二位为当前位置的。
 * 情况一：00,30,40,50,60,70,80,90:错误，无法解析return 0;
 * 情况二：10,20：dp[i] = dp[i-2];
 * 情况三：[11,19],[21,26]：dp[i] = dp[i-1] + dp[i-2];
 * 情况四：剩下的：dp[i] = dp[i-1]
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0 || s.at(0) == '0') {
			return 0;
		}
		int dpNumOfWays[s.size()];
		dpNumOfWays[0] = 1;
		for(size_t i = 1; i < s.size(); i++){
			if((s.at(i) == '0' && s.at(i-1) == '0') || (s.at(i) == '0' && s.at(i-1) > '2')){
				return 0;
			}else if(s.at(i)=='0' && (s.at(i-1) == '1' || s.at(i-1) == '2')  ){
				if( (static_cast<int>(i)-2) < 0){
					dpNumOfWays[i] = 1;
				}else{
					dpNumOfWays[i] = dpNumOfWays[i-2];
				}
			}else if((s.at(i) >= '1' && s.at(i) <= '9' && s.at(i-1) == '1') || (s.at(i) >= '1' && s.at(i) <= '6' && s.at(i-1) == '2')){
				if( (static_cast<int>(i)-2) < 0){
					dpNumOfWays[i] = dpNumOfWays[i-1] + 1;
				}else{
					dpNumOfWays[i] = dpNumOfWays[i-1] + dpNumOfWays[i-2];
				}
			}else{
				dpNumOfWays[i] = dpNumOfWays[i-1];
			}
		}
		return dpNumOfWays[s.size()-1];
	}
};

int main() {
	Solution s;
	cout << s.numDecodings("230");
	return 0;
}

/*
 * LongestPalindromicSubstring.cpp
 *
 *  Created on: 2015年3月27日
 *      Author: netbeen
 */


/*
 * 动态规划求最长回文子串的算法。
 */

#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if(s.size()==1){
			return s;
		}
		int maxLength = 0;	//记录最长子串长度
		int maxStartIndex = 0;	//记录最长字串开始索引
		bool dp[s.size()][s.size()];	// dp规则：dp[i][j]表示：从i到j是否为回文
		for(int i = 0; i < static_cast<int>(s.size()); i++){
			dp[i][i] = true;		// 初始化主对角线，从i到i肯定是回文，只有一个字符
		}
		for(int i = 0; i < static_cast<int>(s.size())-1; i++){	//初始化第二斜线，两个字符若是回文，必然相同。
			if(s.at(i) == s.at(i+1)){
				dp[i][i+1] = true;
				maxLength =2;
				maxStartIndex = i;
			}else{
				dp[i][i+1]=false;
			}
		}
		for(int testLength = 2; testLength < static_cast<int>(s.size()); testLength++){	//初始化剩余的上三角，例如dp[2][6]为true的必要条件是，dp[3][4]为true，并且s[2]和s[6]相同。
			for(int startIndex = 0; startIndex < static_cast<int>(s.size()) - testLength; startIndex++){
				if (  (dp[startIndex+ 1][startIndex+testLength - 1] == true) &&  (s.at(startIndex) == s.at(startIndex+testLength))   ){
					dp[startIndex][startIndex+testLength] = true;
					maxLength = testLength +1;
					maxStartIndex = startIndex;
				}else{
					dp[startIndex][startIndex+testLength] = false;
				}
			}
		}
		string result;
		for(int i = 0; i <maxLength;i++ ){
			result.append(1,s.at(maxStartIndex + i));
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.longestPalindrome("abb");
	return 0;
}

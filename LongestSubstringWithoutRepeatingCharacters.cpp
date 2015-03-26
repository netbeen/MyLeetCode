/*
 * LongestSubstringWithoutRepeatingCharacters.cpp
 *
 *  Created on: 2015年3月26日
 *      Author: netbeen
 */

/*
 * 统计不重复的最长字符字串：思想，两个游标，游标中间表示一个移动窗口，窗口中包含着的是最近的不重复字符。
 * 同时用一个大小为256的数组存放不同的字母上次出现的位置。
 *	遍历一边字符串即可，时间复杂度O(n)
 */

#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int hashRecord[256];
    	memset(hashRecord, -1, sizeof(hashRecord));

    	int curSubstringStart = 0;
    	if(s.empty() == true){
    		return 0;
    	}
    	int maxLength = 0;
    	for(int i = 0; i < s.size(); i++){
    		if (hashRecord[static_cast<int>(s.at(i))] >= curSubstringStart){	//	该字符已经出现过并且在窗口中
    			curSubstringStart =hashRecord[static_cast<int>(s.at(i))] +1;
    		}else{		// 该字符从未出现过 或者 已经出现过但不在窗口中
    			maxLength = max(maxLength, i - curSubstringStart + 1);
    		}
    		hashRecord[static_cast<int>(s.at(i))] = i;
    	}
    	return maxLength;
    }
};

int main(){
	string str = "tmmzuxt";
	Solution s;
	cout << s.lengthOfLongestSubstring(str);
	return 0;
}

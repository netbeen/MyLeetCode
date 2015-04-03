/*
 * ImplementStrStr.cpp
 *
 *  Created on: 2015年4月3日
 *      Author: netbeen
 */

/*
 * 在字符串haystack中寻找和needle匹配的子串。
 * 运用类似滑动窗口的方法，时间复杂度O(m*n)
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	if(needle[0] == '\0'){
    		return 0;
    	}
    	int haystackCursor = 0;
    	int compareCursor = 0;
    	while(haystack[haystackCursor + compareCursor] != '\0' && needle[compareCursor] != '\0'){
    		if(haystack[haystackCursor + compareCursor] == needle[compareCursor]){
    			compareCursor++;
    		}else{
    			haystackCursor++;
    			compareCursor=0;
    		}
    		if(needle[compareCursor] == '\0'){
    			return haystackCursor;
    		}
    	}
    	return -1;
    }
};

int main(){
	Solution s;
	cout << s.strStr("a","a");
	return 0;
}

/*
 * LengthOfLastWord.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 计算最后一个单词的长度，没啥技术含量
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
	    const int n = strlen(s);
	    int length = 0;

	    for(int i = 0; i < n; ++i){
	        if(s[i] != ' ') length++;
	        else if(i+1 < n && s[i+1] != ' ') length = 0;
	    }
	    return length;
	}

	int lengthOfLastWord2(const char *s) {
		int recentSpace = -1;
		int charIndex = 0;
		while (s[charIndex] != 0) {
			if (s[charIndex] == ' ') {
				recentSpace = charIndex;
			}
			charIndex++;
		}
		return charIndex - recentSpace - 1;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLastWord("") << endl;
	cout << s.lengthOfLastWord("a") << endl;
	cout << s.lengthOfLastWord("Hello") << endl;
	cout << s.lengthOfLastWord("Hello world") << endl;
	return 0;
}

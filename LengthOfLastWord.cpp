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
		bool valid = false;
		int lastLen = 0;
		int charIndex = 0;
		while (s[charIndex] != '\0') {
			if (s[charIndex] == ' ') {
				if(valid == true){
					valid = false;
				}
			}else{
				if(valid == false){
					lastLen = 0;
					valid = true;
				}
				lastLen++;
			}
			charIndex++;
		}
		return lastLen;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLastWord("") << endl;
	cout << s.lengthOfLastWord("a ") << endl;
	cout << s.lengthOfLastWord("Hello") << endl;
	cout << s.lengthOfLastWord("Hello world") << endl;
	cout << s.lengthOfLastWord("Hello world Hello world!") << endl;
	return 0;
}


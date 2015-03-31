/*
 * ValidParentheses.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */


/*
 * 判断括号(){}[]是否配对的问题。
 * 运用一个栈，每次左括号入栈，右括号（先验证）出栈并配对
 * 检测完毕在看看栈是否为空（是否有残留）
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> charStack;
		for (size_t i = 0; i < s.size(); i++) {
			switch (s.at(i)) {
			case '(':
				charStack.push('(');
				break;
			case '[':
				charStack.push('[');
				break;
			case '{':
				charStack.push('{');
				break;
			case ')':
				if (charStack.empty() == true  || charStack.top() != '(') {
					return false;
				} else {
					charStack.pop();
				}
				break;
			case ']':
				if (charStack.empty() == true  || charStack.top() != '[') {
					return false;
				} else {
					charStack.pop();
				}
				break;
			case '}':
				if (charStack.empty() == true  ||  charStack.top() != '{') {
					return false;
				} else {
					charStack.pop();
					break;
				}
			}
		}
		return charStack.empty();

	}
};

int main() {
	Solution s;
	cout << s.isValid("[") << endl;;
	cout << true;
}

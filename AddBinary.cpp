/*
 * AddBinary.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 模拟二进制加法，没啥技术含量
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	char oneBitAdd(char charA, char charB) {
		short intA = (charA == '0') ? 0 : 1;
		short intB = (charB == '0') ? 0 : 1;
		short carry = (carryBit == false) ? 0 : 1;
		short result = intA + intB + carry;
		switch (result) {
		case 0:
			carryBit = false;
			return '0';
		case 1:
			carryBit = false;
			return '1';
		case 2:
			carryBit = true;
			return '0';
		case 3:
			carryBit = true;
			return '1';
		}
	}

	string addBinary(string a, string b) {
		if (a.size() == 0 && b.size() == 0) {
			return "0";
		} else if (a.size() == 0) {
			return b;
		} else if (b.size() == 0) {
			return a;
		}
		carryBit = false;
		string resultReserve;
		for (size_t i = 0; i < min(a.size(), b.size()); i++) {
			char temp = oneBitAdd(a.at(a.size() - 1 - i), b.at(b.size() - 1 - i));
			resultReserve.append(1, temp);
		}
		if (resultReserve.size() == a.size()) {
			for (size_t i = resultReserve.size(); i < b.size(); i++) {
				char temp = oneBitAdd('0', b.at(b.size() - 1 - i));
				resultReserve.append(1, temp);
			}
		} else {
			for (size_t i = resultReserve.size(); i < a.size(); i++) {
				char temp = oneBitAdd('0', a.at(a.size() - 1 - i));
				resultReserve.append(1, temp);
			}
		}
		if (carryBit == true) {
			resultReserve.append(1, '1');
		}

		string result;
		stack<char> charStack;
		bool valid = false;
		for (size_t i = 0; i < resultReserve.size(); i++) {
			charStack.push(resultReserve.at(i));
		}
		while (charStack.empty() == false) {
			if (valid == false && charStack.top() == '0') {
				;
			} else {
				valid = true;
				result.append(1, charStack.top());
			}
			charStack.pop();
		}
		return (result.empty() == false) ? result : "0";
	}
private:
	bool carryBit;
};

int main() {
	Solution s;

	cout << s.addBinary("11", "1") << endl;
	cout << s.addBinary("000", "1") << endl;
	cout << s.addBinary("", "1") << endl;
	cout << s.addBinary("0", "0") << endl;
	return 0;
}

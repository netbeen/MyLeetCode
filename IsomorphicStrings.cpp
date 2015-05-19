/*
 * IsomorphicStrings.cpp
 *
 *  Created on: 2015年5月14日
 *      Author: netbeen
 */

/*
 * 用两个map，一个为从s映射到t的map，另一个为从t映射回s的map。
 * 可以保证充分必要的条件满足。
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty() == true && t.empty() == true)
			return true;
		if (s.empty() != t.empty())
			return false;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			it = s2t.find(s.at(i));
			if (it != s2t.end()) {	//在s2t中找到
				if (it->second != t.at(i)) {	//若映射错误
					return false;
				}
			} else {
				s2t[s.at(i)] = t.at(i);
			}

			it = t2s.find(t.at(i));
			if (it != t2s.end()) {//在t2s中找到
				if (it->second != s.at(i)) {	//若映射错误
					return false;
				}
			} else {
				t2s[t.at(i)] = s.at(i);
			}
		}
		return true;
	}

private:
	map<char, char> s2t;
	map<char, char> t2s;
	map<char, char>::iterator it;
};

int main() {
	Solution s;
	cout << s.isIsomorphic("ab", "ca");
	cout << s.isIsomorphic("ab", "aa");
	return 0;
}

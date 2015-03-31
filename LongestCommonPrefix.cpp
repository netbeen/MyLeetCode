/*
 * LongestCommonPrefix.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */


/*
 * 寻找最长的公共前缀，
 * 选取第一个字符串的每一个字符，和下面的进行比对，如果全部相同，就添加到子串中。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.size() == 0){
    		return "";
    	}
    	string result;
    	for(size_t i = 0; i < strs.at(0).size(); i++){
    		for(size_t j = 1; j < strs.size();j++){
    			if(  (i >= strs.at(j).size())   ||   (strs.at(j).at(i) !=strs.at(0).at(i))){		//第一个条件要判别后续的字符串的长度是否已经比i小了，防止越界异常
    				return result;
    			}
    		}
    		result.append(1,strs.at(0).at(i));
    	}
    	return result;
    }
};

int main(){
	vector<string> strs;
	strs.push_back("aa");
	strs.push_back("a");
	Solution s;
	cout << s.longestCommonPrefix(strs);
}

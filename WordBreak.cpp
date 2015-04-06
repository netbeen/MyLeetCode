/*
 * WordBreak.cpp
 *
 *  Created on: 2015年4月6日
 *      Author: netbeen
 */

/*
 * 切分string，判断是否能够解析成字典元素。
 * 利用动态规划。dp[i]表示，到i为止，能否被表示。
 * 检测第i个字符时，检查一下，dp[0] 至 dp[i-1]是否有true的，若第j为true，则判断该j至i的substring能否被字典解析。
 *
 */

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	if(s.empty()){
    		return false;
    	}
    	vector<bool> dpCanBeResolve(s.size()+1,false);
    	dpCanBeResolve.at(0) = true;
    	for(size_t cursor = 0; cursor < s.size(); cursor++){
    		for(int previous = cursor; previous >= 0; previous--){
    			if(dpCanBeResolve.at(previous) == true){
    				string str = s.substr(previous, cursor-previous+1);
    				if(dict.find(str) != dict.end()){
    					dpCanBeResolve.at(cursor+1) = true;
    				}
    			}
    		}
    	}
    	return dpCanBeResolve.at(s.size()-1+1);
    }
};

int main(){
	Solution s;
	unordered_set<string> dict;
	dict.insert("a");
	//dict.insert("code");
	cout << s.wordBreak("a", dict);
	return 0;
}

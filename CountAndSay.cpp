/*
 * CountAndSay.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 * 写出一种数字的念法
 * 第一组：1:11
 * 第二组：11:21
 * 第三组：21:1211
 * 第四组：1211:111221
 *
 * 以此类推，构建一个基于string的vector，最后返回最后一个string
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	vector<string> strings;
    	strings.push_back("1");
    	for(int i = 1; i < n; i++){
    		string formerString = strings.at(i-1);

    		int curNum = 0;
    		char curChar = formerString.at(0);
    		string result;
    		for(int i = 0; i < formerString.size();i++){
    			if(formerString.at(i) == curChar){	//如果与缓存字符相同的情况
    				curNum ++;
    			}else{		//如果与缓存字符不同的情况
    				result.append(1,static_cast<char>(curNum + 48));
    				result.append(1,curChar);
    				curChar = formerString.at(i);
    				curNum = 1;
    			}
    			if( i == formerString.size() -1){		//处理最后一组相同字符
    				result.append(1,static_cast<char>(curNum + 48));
    				result.append(1,curChar);
    			}
    		}
    		strings.push_back(result);
    	}
    	return strings.at(n-1);
    }
};

int main(){
	Solution s;
	s.countAndSay(1);
	return 0;
}

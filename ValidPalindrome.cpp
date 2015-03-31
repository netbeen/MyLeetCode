/*
 * ValidPalindrome.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */

/*
 * 判断字符串是否为回文，检测包括数字，忽略大小写。
 * 先进行一边预处理，完成大小写转换，标记出所有要删除的非法字符
 * 删除非法字符
 * 双指针进行检测
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	stack<int> toBeDelete;
    	for(size_t i = 0 ; i < s.size(); i++){
    		if (((s.at(i) >= 'a') && (s.at(i)  <= 'z'))        ||         ((s.at(i) >= '0') && (s.at(i)  <= '9'))   ){
    			continue;
    		}else if((s.at(i) >= 'A' )  && (s.at(i) <= 'Z')){
    			s.at(i) += 32;
    		}else{
    			toBeDelete.push(i);
    		}
    	}

    	while(toBeDelete.empty() == false){
    		s.erase(toBeDelete.top(),1);
    		toBeDelete.pop();
    	}

    	for(int i = 0, j = s.size()-1; i <= j; i++,j--){
    		if(s.at(i) != s.at(j)){
    			return false;
    		}
    	}
    	return true;
    }
};

int main(){
	Solution s;
	cout << s.isPalindrome("1A man, a plan, a canal: Panama2");
	return 0;
}

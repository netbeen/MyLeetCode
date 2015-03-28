/*
 * PalindromeNumber.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 */

/*
 * 判定回文，利用栈和队列的性质进行判别
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<0) return false;
    	queue<int> numQueue;
    	stack<int> numStack;
    	//每一位同时入栈和入队
    	while(x != 0){
    		numQueue.push(x%10);
    		numStack.push(x%10);
    		x /= 10;
    	}
    	//同时出栈和出队
    	while(numQueue.empty() == false){
    		if(numQueue.front() == numStack.top()){
    			numQueue.pop();
    			numStack.pop();
    		}else{
    			return false;
    		}
    	}
    	return true;
    }
};

int main(){
	Solution s;
	cout << s.isPalindrome(-2147447412);
	return 0;
}

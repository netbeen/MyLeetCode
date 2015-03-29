/*
 * MinStack.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */


/*
 * 要求实现一个能在O(1)时间内返回最小值的栈。
 * 我采用两个STL栈，一个是正常的栈，一个是最小值栈。
 * 当且仅当push x时候，x<=最小栈的栈顶元素，才push进最小栈
 * 当且仅当pop的时候，正常栈的栈顶元素=最小栈的栈顶元素，才pop最小栈。
 */

#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
    	if((minStack.empty() == true) || (minStack.top() >= x) ){
    		minStack.push(x);
    	}
    	numStack.push(x);
    }

    void pop() {
    	if(numStack.top() == minStack.top()){
    		minStack.pop();
    	}
    	numStack.pop();
    }

    int top() {
    	return numStack.top();
    }

    int getMin() {
    	return minStack.top();
    }
private:
    stack<int> numStack;
    stack<int> minStack;
};

int main(){
	MinStack s;
	s.push(0);
	s.push(1);
	s.push(0);

	return 0;
}

/*
 * LinkedListCycle.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 经典链表找环算法
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(head == NULL){
			return false;
		}
		ListNode* fastPointer;
		ListNode* slowPointer;
		fastPointer = slowPointer = head;
		while(fastPointer->next != NULL){
			if(fastPointer->next->next != NULL){
				fastPointer = fastPointer->next->next;
				slowPointer = slowPointer->next;
				if(fastPointer == slowPointer){
					return true;
				}
			}else{
				return false;
			}
		}
	}
};

int main(){
	return 0;
}

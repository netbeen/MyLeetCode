/*
 * RemoveDuplicatesFromSortedListII.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */




/**
 * Definition for singly-linked list.*/

/*
 * 删除所有链表中的重复元素。
 * 输入：1->1->1->2->3
 * 输出：2->3
 *
 * 用两个指针，一个指向上一个不重复元素，另一个指向现在遍历的元素。
 * 逻辑比较绕，最后参考的网上答案，没有细究。
 */

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

    	if(head == NULL || head->next == NULL){
    		return head;
    	}

    	ListNode* dummyHead = new ListNode(-1);
    	dummyHead->next = head;

    	ListNode* lastNoneDuplicateNode = dummyHead;
    	ListNode* cursor = head;

    	while(cursor != NULL){
    		while(cursor->next != NULL &&  lastNoneDuplicateNode->next->val == cursor->next->val){
    			cursor = cursor->next;
    		}
    		if(lastNoneDuplicateNode->next == cursor){
    			lastNoneDuplicateNode = cursor;
    		}else{
    			lastNoneDuplicateNode->next = cursor->next;
    		}
    		cursor = cursor->next;
    	}
    	return dummyHead->next;
    }
};

int main(){
	Solution s;

	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);

	head = s.deleteDuplicates(head);

	ListNode* cursor = head;
	while(cursor != NULL){
		cout << cursor->val << "->";
		cursor = cursor->next;
	}


	return 0;
}

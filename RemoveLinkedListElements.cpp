/*
 * RemoveLinkedListElements.cpp
 *
 *  Created on: 2015年5月19日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.
 */

/*
 * 链表中删除val为特定值的节点。
 * 链表的删除操作中，一般都涉及到头节点被删除的特殊操作，比较复杂，一律采用dummyHead的方式给链表加一个假的头节点。
 * 然后删除的方式就统一了：cur->next = cur->next->next;（删除了cur->next 节点）
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if(head == NULL){
			return NULL;
		}
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		for(ListNode* cur = dummyHead; cur->next != NULL; ){
			if(cur->next->val == val){
				cur->next = cur->next->next;
			}else{
				cur = cur->next;
			}
		}
		return dummyHead->next;

	}
};

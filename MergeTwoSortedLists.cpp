/*
 * MergeTwoSortedLists.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 归并两个有序链表为一个有序链表。
 * 产生一个head指针，初始化指向l1和l2头节点中较小的那个，保持不动。
 * 产生一个cursor指针，指向当前归并完成的链表的末尾，每次移动。
 * 原来的l1和l2两个指针，在程序运行过程中，分别指向两个链表中未被归并的头部。
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		ListNode* head;
		ListNode* cursor;
		if (l1->val < l2->val) {
			head = l1;
			cursor = l1;
			l1 = l1->next;
		} else {
			head = l2;
			cursor = l2;
			l2 = l2->next;
		}
		while ((l1 != NULL) && (l2 != NULL)) {
			if (l1->val < l2->val) {
				cursor->next = l1;
				cursor = cursor->next;
				l1 = l1->next;
			} else {
				cursor->next = l2;
				cursor = cursor->next;
				l2 = l2->next;
			}
		}
		if(l1 == NULL){
			cursor->next = l2;
		}else{
			cursor->next = l1;
		}
		return head;
	}
};


int main(){
	ListNode* l1 = new ListNode(5);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(2);
	l2->next->next = new ListNode(4);

	Solution s;
	ListNode* head = s.mergeTwoLists(l1,l2);
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}

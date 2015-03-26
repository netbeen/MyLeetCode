/*
 * AddTwoNumbers.cpp
 *
 *  Created on: 2015年3月26日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.
 */

/*
 * 考察单链表的构建方法，运用三个指针，一个是头节点指针，第二个为尾节点指针，第三个为新增节点指针
 */

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* result = NULL;
		ListNode* curTailNode = NULL;
		ListNode* newNode = NULL;
		int carryBit = 0;
		while (l1 != NULL || l2 != NULL || carryBit != 0) {
			int l1val,l2val = 0;
			if (l1 == NULL) {
				l1val = 0;
			} else {
				l1val = l1->val;
				l1 = l1->next;
			}
			if (l2 == NULL) {
				l2val = 0;
			} else {
				l2val = l2->val;
				l2 = l2->next;
			}
			int sum = l1val + l2val + carryBit;
			carryBit = 0;
			if (sum > 9) {
				sum -= 10;
				carryBit = 1;
			}
			newNode = new ListNode(sum);
			if (result == NULL) {
				result = newNode;
				curTailNode = result;
			} else {
				curTailNode->next = newNode;
				curTailNode = curTailNode->next;
			}
		}
		return result;
	}
};

int main() {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(1);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution s;
	ListNode* result = s.addTwoNumbers(l1, l2);
	while (result != NULL) {
		std::cout << result->val << "->";
		result = result->next;
	}

	return 0;
}

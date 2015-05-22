/*
 * ReorderList.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 将链表的顺序改变，
 * 输入：L: L0→L1→…→Ln-1→Ln,
 * 输出：L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * 思想：先将链表从中间切分，然后将后一段链表逆置，最后将两个链表间隔输出。
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
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return;
		}

		// 建立头节点，统一链表操作。
		ListNode* dummyHead = new ListNode(-1);
		ListNode* cursor = dummyHead;
		ListNode* fastPtr = head;
		ListNode* slowPtr = head;

		//用快慢指针分割链表
		while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}

		//断链
		ListNode* head2 = slowPtr->next;
		slowPtr->next = NULL;

		//head2逆置
		head2 = this->reverseList(head2);

		//间隔输出
		bool nowTurnHead1 = true;
		while (head != NULL || head2 != NULL) {
			if (nowTurnHead1 == true) {
				cursor->next = head;
				cursor = cursor->next;
				head = head->next;
				nowTurnHead1 = false;
			} else {
				cursor->next = head2;
				cursor = cursor->next;
				head2 = head2->next;
				nowTurnHead1 = true;
			}
		}

	}
private:
	//逆置算法，还是采用三指针方式，核心操作三步走
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* pre = head;
		ListNode* cur = head->next;
		while (cur != NULL) {
			ListNode* next = cur->next;

			//三步核心操作
			cur->next = dummyHead->next;
			dummyHead->next = cur;
			pre->next = next;
			//核心操作结束

			cur = pre->next;
		}
		return dummyHead->next;

	}
};

int main() {

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	/*head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);*/

	ListNode* cur = head;

	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}

	Solution s;
	s.reorderList(head);
	//head = s.reverseList(head);

	cur = head;

	cout << endl;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	return 0;
}

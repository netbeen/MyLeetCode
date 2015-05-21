/*
 * ReverseLinkedList.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 单链表逆置法：参考 http://www.nowamagic.net/librarys/veda/detail/2241
 * 首先，给链表加一个DummyHead，保证操作的一致性。
 * 初始定位：
 * pre = dummyHead->next;
 * cur = pre->next;
 * next = cur->next;
 *
 * 每一次向后集体移动一次，并调用换位算法，如下：
 * pre->next = next;
 * cur->next = dummyHead->next;
 * dummyHead->next = cur;
 * 完成个节点的换位，使cur节点成为链表的头节点。
 * 循环该过程。
 *
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
	ListNode* reverseList(ListNode* head) {
		int count = 0;
		ListNode* cursor = head;
		while (cursor != NULL) {
			cursor = cursor->next;
			count++;
		}
		if (count < 2) {
			return head;
		}
		nodeCount = count;
		dummyHead = new ListNode(0);
		dummyHead->next = head;

		for (int i = 2; i <= count; i++) {
			reverseNodeWithDummyHead(i);
		}

		return dummyHead->next;
	}

	void reverseNodeWithDummyHead(int index) {
		ListNode* pre = dummyHead->next;
		ListNode* cur = pre->next;
		ListNode* next = cur->next;

		for (int i = 0; i < index - 2; i++) {
			pre = pre->next;
			cur = cur->next;
			next = next->next;
		}

		pre->next = next;
		cur->next = dummyHead->next;
		dummyHead->next = cur;
	}

private:
	ListNode* dummyHead;
	int nodeCount;
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);

	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}

	Solution s;
	head = s.reverseList(head);

	cout << endl;
	cur = head;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}

	return 0;
}

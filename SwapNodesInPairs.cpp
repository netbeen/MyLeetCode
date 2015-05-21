/*
 * SwapNodesInPairs.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 题目意思：链表节点两两逆置
 * 分析：依然采用链表逆置算法，定下3指针，然后换next。画图分析即可。
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
private:
	ListNode* dummyHead;
	ListNode* pre;
	ListNode* cur;
	ListNode* prePre;
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) {		//处理空链表
			return head;
		}else if(head->next == NULL){		//只有一个节点，直接返回
			return head;
		}
		dummyHead = new ListNode(-1);
		dummyHead->next = head;

		prePre = dummyHead;	//初始化三个指针
		pre = prePre->next;
		cur = pre->next;

		while (true) {
			//实际执行换位
			pre->next = cur->next;
			cur->next = pre;
			prePre->next = cur;

			//判断继续条件
			if (pre->next != NULL && pre->next->next != NULL) {
				prePre = pre;
				pre = prePre->next;
				cur = pre->next;
			} else {
				break;
			}
		}

		return dummyHead->next;

	}

};

int main() {
	Solution s;

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);

	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	cur = head = s.swapPairs(head);
	cout << endl;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}

	return 0;
}

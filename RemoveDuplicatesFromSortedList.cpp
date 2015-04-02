/*
 * RemoveDuplicatesFromSortedList.cpp
 *
 *  Created on: 2015年4月2日
 *      Author: netbeen
 */

/*
 * 在一个元素有序的链表中剔除重复元素
 * 用两个指针cursor指向当前处理的指针，cursorForward去寻找下一个不同的元素
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
	ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL){
			return head;
		}else if(head->next == NULL){
			return head;
		}
		ListNode* cursor = head;
		ListNode* cursorForward = head->next;
		while(cursorForward != NULL){
			if(cursorForward->val != cursor->val){	//找到下一个不同元素
				cursor->next = cursorForward;
				cursor = cursorForward;
			}
			cursorForward = cursorForward->next;
		}
		cursor->next = NULL;
		return head;
	}
};

void printList(ListNode *head) {
	if (head == NULL) {
		cout << "NULL" << endl;
	}
	cout << head->val << " -> ";
	while (head->next != NULL) {
		head = head->next;
		cout << head->val << " -> ";
	}
	cout << endl;
}

int main() {
	Solution s;
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(1);
	head1->next->next = new ListNode(2);
	head1->next->next->next = new ListNode(3);
	head1->next->next->next->next = new ListNode(3);
	head1 = s.deleteDuplicates(head1);
	printList(head1);

	ListNode* head2 = NULL;
	head2 = s.deleteDuplicates(head2);
	printList(head2);

	return 0;
}

/*
 * PartitionList.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 链表划分算法：给定一个枢轴x，链表中任何小于x的节点要放到>=x的节点的前面。
 * 思路：双指针法。一个指针指向“小节点”子链表的尾部，另一个指向当前操作的节点。
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
	ListNode* partition(ListNode* head, int x) {
		//建立头节点，统一链表操作
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* tailOfSmallValueNode = dummyHead;
		ListNode* preCursor = dummyHead;


		while(preCursor->next != NULL){
			if(preCursor->next->val < x){	//如果该节点需要被提到前面去
				ListNode* swapCursor = preCursor->next;

				preCursor->next = swapCursor->next;

				swapCursor->next = tailOfSmallValueNode->next;
				tailOfSmallValueNode->next = swapCursor;
				tailOfSmallValueNode = tailOfSmallValueNode->next;

				if(preCursor->next == tailOfSmallValueNode){	//为了处理初始状态，两个指针重合的时候，需要带着preCursor走，不然会出现bug
					preCursor = tailOfSmallValueNode;
				}

			}else{	//如果该节点不需要被提到前面去
				preCursor = preCursor->next;
			}
		}

		return dummyHead->next;

	}
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(1);

	ListNode* cursor = head;

	while (cursor != NULL) {
		cout << cursor->val << "->";
		cursor = cursor->next;
	}

	Solution s;
	cursor = s.partition(head, 3);

	cout << endl;

	while (cursor != NULL) {
		cout << cursor->val << "->";
		cursor = cursor->next;
	}

	return 0;
}

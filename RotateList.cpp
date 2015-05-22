/*
 * RotateList.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */

/**
 * Definition for singly-linked list.*/

/*
 * 链表右旋。
 *
 * 先根据要求位移数%链表长度=实际位移数
 * 然后在实际位移处切分链表，重新链接即可。
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
	ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || head->next == NULL){
			return head;
		}

		//统计链表长度并计算实际位移
		int nodeNum = this->getSize(head);
		k = k%nodeNum;
		if(k == 0){
			return head;
		}

		//ＤummyＨead统一操作。
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* cursor = dummyHead;
		for(int i = 0; i < nodeNum - k ; i++){
			cursor = cursor->next;
		}
		ListNode* head2 = cursor->next;
		cursor->next = NULL;

		dummyHead->next = head2;
		cursor = head2;
		while(cursor->next != NULL){
			cursor = cursor->next;
		}
		cursor->next = head;

		return dummyHead->next;

	}

private:
	int getSize(ListNode* head){
		if(head == NULL){
			return 0;
		}
		int count = 0;
		while(head != NULL){
			count ++;
			head = head->next;
		}
		return count;
	}
};

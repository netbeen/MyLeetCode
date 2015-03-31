/*
 * RemoveNthNodeFromEndOfList.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */

/*
 * 在单链表中删除倒数第n个元素，只允许扫描一遍。
 * 用一个后拖指针跟着，即可，最后删除。
 *
 * 难点：头节点的处理
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {

		ListNode* front = head;
		ListNode* back = head;
		for(int i = 0 ; i < n; i ++){
			if((front->next == NULL) && (front == head)){	//如果该链表只有一个头节点的情况
				return NULL;
			}else if((front->next == NULL) && (front != head)){		//如果该链表不止1个节点，但是要删除头节点的情况
				return head->next;
			}
			front = front->next;
		}
		while(front->next != NULL){
			front = front->next;
			back = back->next;
		}
		back->next = back->next->next;
		return head;
	}
};

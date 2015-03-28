/*
 * IntersectionOfTwoLinkedLists.cpp
 *
 *  Created on: 2015年3月28日
 *      Author: netbeen
 /**
 * Definition for singly-linked list.*/

/*
 * 寻找两个链表的交汇点的问题。要求时间复杂度为O(n)，空间复杂度为O(1)
 * 首先遍历两条链表，获取两个长度，比如A长度为8，B长度为5.
 * 那么A游标前进3次，之后再同B游标同时前进，每次都判断AB游标是否指向同一节点，若是，则返回该节点
 * 若同时前进至末尾，AB游标都没有相等，则说明没有交汇，返回NULL
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if ((headA == NULL) || (headB == NULL)) {	// 解决空指针的问题
			return NULL;
		}
		int lengthA = 0;
		int lengthB = 0;
		for (ListNode* cursor = headA; cursor->next != NULL; cursor = cursor->next) {		//遍历两条链表获得长度
			lengthA++;
		}
		for (ListNode* cursor = headB; cursor->next != NULL; cursor = cursor->next) {
			lengthB++;
		}
		ListNode* cursorA = headA;
		ListNode* cursorB = headB;
		if (lengthA > lengthB) {		// 长的那段链表前进（A-B）或者（b-a）次
			for (int i = 0; i < (lengthA - lengthB); i++) {
				cursorA = cursorA->next;
			}
		} else {
			for (int i = 0; i < (lengthB - lengthA); i++) {
				cursorB = cursorB->next;
			}
		}
		while (cursorA->next != NULL) {	//开始同时前景
			if (cursorA == cursorB) {
				return cursorA;
			} else {
				cursorA = cursorA->next;
				cursorB = cursorB->next;
			}
		}
		if (cursorA == cursorB) {	//处理最后一个节点，判断是否交汇
			return cursorA;
		} else {
			return NULL;
		}
	}
};
